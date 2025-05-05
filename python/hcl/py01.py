# grades= (55,60,65,78,45,89,45,68,98,96,96,99)
# def drop_first_last(grades):
#     _,*middle,last = grades
#     return sum(middle)/(len(grades)-2)
# print('平均数：',drop_first_last(grades))

# record = ('Dave', 'dave@example.com', '773-555-1212', '847-555-1212')

# records =[
#     ('foo', 1, 2),
#     ('bar', 'hello'),
#     ('foo', 3, 4)
#     ]
# def do_foo(x,y):
#    print('foo',x,y)
# def do_bar(s):
#    print('bar',s)
# for tag, *args in records:
#     if tag =='foo':
#         do_foo(*args)
#     elif tag== 'bar':
#         do_bar(*args)

 # Exampleuseonafile
from collections import deque


def search(lines,pattern,history=5):
    previous_lines =deque(maxlen=history)
    for li in lines:
        if pattern in li:
            yield li,previous_lines
        previous_lines.append(li)

if __name__ =='__main__':
    with open(r'd:/src/codesnippet/python/hcl/py01.py') as f:
        for line,prevlines in search(f,'python',5):
            for pline in prevlines:
                print(pline,end='')
            print(line,end='')
            print('-'*20)

