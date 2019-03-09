
def solve(case_id):
	n = int(raw_input())
	items = []
	for i in xrange(n):
		items.append(int(raw_input()))
	items.sort(reverse=True)
	usage = 0
	for index, item in enumerate(items):
		usage += 50 // item + int(50 % item != 0)
		if usage > len(items):
			break 
	if usage <= len(items):
		index += 1
	print 'Case #{}: {}'.format(case_id, index)


def main():
	t = int(raw_input())
	for i in xrange(1, t + 1):
		solve(i)


if __name__ == '__main__':
	main()