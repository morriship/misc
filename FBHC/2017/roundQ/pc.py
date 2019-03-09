
def build_dice(pre, now, dice):
	for i in xrange(dice + len(pre)):
		val = 0
		for j in xrange(1, dice + 1):
			k = i - j
			if k < 0:
				break
			if k < len(pre):
				val += pre[k]
		now.append(val)


def ch_sum(table):
	s = sum(table)
	t = 0.0
	for i in xrange(len(table) - 1, 0, -1):
		t += table[i]
		table[i] = t / s

def build_y(table, dice):
	for i in xrange(21):
		table.append([])
	t = table[1]
	t.append(0)
	for i in xrange(dice):
		t.append(1)
	for i in xrange(2, 21):
		build_dice(table[i - 1], table[i], dice)
	for i in xrange(21):
		ch_sum(table[i])


def build_dp():
	table = [[] for i in xrange(21)]
	able_y_list = [4, 6, 8, 10, 12, 20]
	for able_y in able_y_list:
		build_y(table[able_y], able_y)
	return table


def parse_spell(spell):
	x, meta = spell.split('d')
	x = int(x)
	if '-' in meta:
		y, z = map(lambda x: int(x), meta.split('-'))
		z = -z
	elif '+' in meta:
		y, z = map(lambda x: int(x), meta.split('+'))
	else:
		y = int(meta)
		z = 0
	return (x, y, z)



def calc_spell_prob(spell, h):
	x, y, z = parse_spell(spell)
	h -= z
	if h <= 0:
		return 1.0
	w = dp[y][x]
	if h >= len(w):
		return 0
	return w[h]


def solve(case_id):
	h, s = map(lambda x: int(x), raw_input().split())
	prob = max((calc_spell_prob(spell, h) for spell in raw_input().split()))
	print 'Case #{}: {:.6f}'.format(case_id, prob)




def main():
	t = int(raw_input())
	for i in xrange(1, t + 1):
		solve(i)


if __name__ == '__main__':
	dp = build_dp()
	main()