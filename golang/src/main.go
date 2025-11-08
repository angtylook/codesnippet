package main

func main() {
	ch := make(chan int, 1)
	var nilCh chan int = nil

	ch <- 1
	nilCh <- 1 // This will cause a panic: send on closed channel
	close(ch)
	ch <- 2   // This will also cause a panic: send on closed channel
	close(ch) // This will not cause a panic: close a closed channel

}
