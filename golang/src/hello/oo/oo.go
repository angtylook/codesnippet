package main

import "fmt"
import "math"

type Circle struct {
	x float64
	y float64
	r float64
}

/**
type Circle struct {
	x, y, r float64
}
*/

func circleArea(c *Circle) float64 {
	return math.Pi * c.r * c.r
}

func (c *Circle) area() float64 {
	return math.Pi * c.r * c.r
}

type Person struct {
	Name string
}

func (p *Person) Talk() {
	fmt.Println("Hi, my name is", p.Name)
}

type Android struct {
	Person
	Model string
}

// interface
type Shape interface {
	area() float64
}

type MultiShape struct {
	shapes []Shape
}

func (m *MultiShape) area() float64 {
	var area float64
	for _, s := range m.shapes {
		area += s.area()
	}
	return area
}

func totalArea(shapes ...Shape) float64 {
	var area float64
	for _, s := range shapes {
		area += s.area()
	}
	return area
}

func main() {
	var emptyCircle Circle
	fmt.Println(circleArea(&emptyCircle))
	fmt.Println(emptyCircle.area())
	// pointer to Circle, aka *Circle
	circlePtr := new(Circle)
	fmt.Println(circleArea(circlePtr))
	fmt.Println(circlePtr.area())
	circleInited := Circle{x: 0, y: 0, r: 5}
	fmt.Println(circleArea(&circleInited))
	fmt.Println(circleInited.area())
	circleInitedAbbr := Circle{0, 0, 5}
	fmt.Println(circleInitedAbbr.area())

	a := new(Android)
	a.Name = "Android"
	a.Person.Talk()
	a.Talk()
}
