# """
# This is Master's API interface.
# You should not implement it, or speculate about its implementation
# """
#class Master(object):
#    def guess(self, word):
#        """
#        :type word: str
#        :rtype int
#        """

class Solution(object):
    def findSecretWord(self, wordlist, master):
        """
        :type wordlist: List[Str]
        :type master: Master
        :rtype: None
        """
        weights = [Counter(word[i] for word in wordlist)  for i in range(6)]
        
        wordlist.sort(key=lambda word: sum(weights[i][c] for i, c in enumerate(word)))

        while wordlist:
            word = wordlist.pop()
            matches = master.guess(word)
            wordlist = [
                other for other in wordlist
                if matches == sum(w == o for w,o in zip(word,other))
            ]
            
        