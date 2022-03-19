#!/usr/local/bin/python3

def show_list(cur :float, count :int, price :float):
    print("n\tconst\tprice\tdiff\tdelta")
    prev = cur
    for n in range (1, 30):
        after = (cur * count + price * n) / (count + n)
        diff = cur - after
        print("{}\t{}\t{:.2f}\t{:.2f}\t{:.2f}".format(n, int(n*price*100), after, diff, prev - after))
        prev = after

if __name__ == "__main__":
    show_list(78.5, 3, 51.8)
