package main

import "fmt"

func main() {
	// fixed array
	var numbers [5]float64
	numbers[0] = 98
	numbers[1] = 93
	numbers[2] = 77
	numbers[3] = 82
	numbers[4] = 83

	var total float64 = 0
	for i := 0; i < len(numbers); i++ {
		total += numbers[i]
	}
	fmt.Println(total / float64(len(numbers)))

	// range for
	numbers_r := [5]float64{98, 93, 77, 82, 83}
	var total_r float64 = 0
	for _, value := range numbers_r {
		total_r += value
	}
	fmt.Println(total_r / float64(len(numbers_r)))

	// slice
	//var emptySlice []float64
	//sliceOfFive := make([]float64, 5)
	//sliceOfFiveInCapTen = make([]float64, 5, 10)
	//arr := []float64{1，2，3，4，5}
	//x := arr[0:5]

	// var emptyMap map[string]int
	strToInt := make(map[string]int)
	strToInt["key"] = 10
	fmt.Println(strToInt["key"])
	delete(strToInt, "key")
	fmt.Println(strToInt["key"])
	if val, ok := strToInt["key"]; ok {
		fmt.Println(val, ok)
	} else {
		fmt.Println("key not found")
	}

	// another way to create map
	elements := map[string]string{
		"H":  "Hydrogen",
		"He": "Helium",
	}
	for k, v := range elements {
		fmt.Println(k, v)
	}

	//map to map
	mmp := map[string]map[string]string{
		"H": map[string]string{
			"name":  "Hydrogen",
			"state": "gas",
		},
	}

	for k, v := range mmp {
		fmt.Println(k, v["name"], v["state"])
	}

}
