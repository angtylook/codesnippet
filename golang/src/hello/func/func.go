package main

import "fmt"

// simple function
func average(xs []float64) float64 {
	total := 0.0
	for _, v := range xs {
		total += v
	}
	return total / float64(len(xs))
}

func namedReturnType() (l string, r string) {
	l = "left"
	r = "right"
	return
}

// variadic functions
func add(args ...int) int {
	total := 0
	for _, v := range args {
		total += v
	}
	return total
}

// closure, this function return another function
// which take no arguments and return uint
func makeEvenGenerator() func() uint {
	i := uint(0)
	return func() (ret uint) {
		ret = i
		i += 2
		return
	}
}

func first() {
	fmt.Println("1 st")
}

func second() {
	fmt.Println("2nd")
}

func main() {
	xs := []float64{98, 93, 77, 82, 83}
	fmt.Println(average(xs))
	fmt.Println(namedReturnType())
	fmt.Println(add(1, 2, 3, 4, 5, 6, 7, 8, 9, 10))
	// expand slice
	is := []int{98, 93, 77, 82, 83}
	fmt.Println(add(is...))
	nextEven := makeEvenGenerator()
	fmt.Println(nextEven())
	fmt.Println(nextEven())
	fmt.Println(nextEven())
	// defer
	defer second()
	first()
}
