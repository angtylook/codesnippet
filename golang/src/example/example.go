package example

import (
    "fmt"
)

const (
    Sunday = iota
    Monday
    Tuesday
    Wednesday
    Thursday
    Friday
    Saturday
    numberOfDays       //private
)

func String_learn() {
    var str string
    str = "hello world"
    ch := str[0]
    fmt.Printf("The length of \"%s\" is %d \n", str, len(str))
    fmt.Printf("The first character of \"%s\" is %c.\n", str, ch)
}

func Slice_learn_1() {
    var myArray [10]int  = [10]int{1,2,3,4,5,6,7,8,9,10}

    var mySlice []int = myArray[:5]

    fmt.Println("Elements of myArray:")
    for _, val := range myArray {
	fmt.Print(val, " ")
    }

    fmt.Println("\nElements of mySlice:")
    for _, val := range mySlice {
	fmt.Print(val, " ")
    }

    fmt.Println()
}

func Slice_learn_2() {
    mySlice := make([]int, 5, 10)
    fmt.Println("len(mySlice):", len(mySlice))
    fmt.Println("cap(mySlice):", cap(mySlice))

    mySlice = append(mySlice, 1,2,3)
    fmt.Println("len(mySlice):", len(mySlice))
    fmt.Println("cap(mySlice):", cap(mySlice))

    mySlice2 := []int{8,9,10}
    mySlice = append(mySlice, mySlice2...)
    fmt.Println("len(mySlice):", len(mySlice))
    fmt.Println("cap(mySlice):", cap(mySlice))
}


