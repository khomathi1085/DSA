from collections import defaultdict

class Node:
    def __init__(self, name=""):
        self.name = name
        self.next = {}
        self.del_flag = False

class Solution:
    def __init__(self):
        self.seen = {}
        self.ans = []
        self.path = []

    def addPath(self, node, path):
        for folder in path:
            if folder not in node.next:
                node.next[folder] = Node(folder)
            node = node.next[folder]

    def dedupe(self, node):
        subfolder = []
        for name in sorted(node.next.keys()):
            subfolder.append(self.dedupe(node.next[name]))
        subfolder_repr = "(" + "".join(subfolder) + ")" if subfolder else ""
        if subfolder_repr:
            if subfolder_repr in self.seen:
                self.seen[subfolder_repr].del_flag = node.del_flag = True
            else:
                self.seen[subfolder_repr] = node
        return node.name + subfolder_repr

    def getPath(self, node):
        if node.del_flag:
            return
        if node.name:
            self.path.append(node.name)
            self.ans.append(self.path[:])
        for name in sorted(node.next.keys()):
            self.getPath(node.next[name])
        if node.name:
            self.path.pop()

    def deleteDuplicateFolder(self, paths):
        root = Node()
        for path in paths:
            self.addPath(root, path)
        self.dedupe(root)
        for name in sorted(root.next.keys()):
            self.getPath(root.next[name])
        return self.ans