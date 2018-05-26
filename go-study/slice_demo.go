package main

import "fmt"

func main() {
	var sli []int

	sli = append(sli, 100)

	fmt.Println(sli[0])
	// 自己指定长度，创建slice
	sli2 := make([]int, 10, 100)

	for i := 0; i < 10; i++ {
		sli2 = append(sli2, i)
	}

	for i := 0; i < 10; i++ {
		fmt.Println(sli2[i])
	}

	fmt.Println(len(sli2))
}
