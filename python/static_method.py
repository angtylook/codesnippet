#/usr/local/bin/python3
#encoding=utf-8

class String:
    @staticmethod
    def is_palindrome(s, case_insensitive=True):
        s = ''.join(c for c in s if c.isalnum())
        if case_insensitive:
            s = s.lower()
        for c in range(len(s)//2):
            if s[c] != s[-c-1]:
                return False
        return True

    @staticmethod
    def get_unique_words(sentence):
        return set(sentence.split())

print(String.is_palindrome('Radar', case_insensitive=False))
print(String.is_palindrome('A nut for a jar of tuna'))
print(String.is_palindrome('Never Odd, or Even!'))
print(String.get_unique_words('I love palindromes. I really really love them!'))

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    @classmethod
    def from_tuple(cls, coords):
        return cls(*coords)

    @classmethod
    def from_point(cls, point):
        return cls(point.x, point.y)

p = Point.from_tuple((3,7))
print(p.x, p.y)
q = Point.from_point(p)
print(q.x, q.y)
