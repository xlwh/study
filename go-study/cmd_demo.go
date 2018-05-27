package main

import (
	"fmt"
	"os/exec"
)

func main() {
	cmd := exec.Command("echo", "-n", "My name is zhanghongbin01")
	// 设置输出为管道
	out, err := cmd.StdoutPipe()
	if err != nil {
		fmt.Println("Open pipe error")
		return
	}
	// 开始执行命令，命令的执行结果会放到管道中
	if err := cmd.Start(); err != nil {
		fmt.Println("Exec command error:", err)
		return
	}

	buf := make([]byte, 5)
	n, err := out.Read(buf)
	if err != nil {
		fmt.Println("Read data error:", err)
		return
	}
	fmt.Printf("%s\n", buf[:n])
}
