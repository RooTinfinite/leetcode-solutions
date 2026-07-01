class ValidWordAbbr:
    def __init__(self, dictionary: List[str]):
        self.shorten = lambda word: word if len(word) <= 2 else word[0]+str(len(word)-2)+word[-1]
        self.abbrev = collections.defaultdict(set)
        for word in dictionary: self.abbrev[self.shorten(word)].add(word)

    def isUnique(self, word: str) -> bool:
        s = self.shorten(word)
        return s not in self.abbrev or word in self.abbrev[s] and len(self.abbrev[s]) == 1