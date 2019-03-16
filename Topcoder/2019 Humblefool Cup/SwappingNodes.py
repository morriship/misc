

class SwappingNodes:

    def swapNodes(self, leaves, n):
        if len(leaves) == 1:
            return leaves
        pre = self.swapNodes(leaves[:len(leaves) / 2], 0)
        suf = self.swapNodes(leaves[len(leaves) / 2:], 0)
        if pre > suf:
            pre, suf = suf, pre
        return pre + suf
