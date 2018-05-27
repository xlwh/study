package main

import (
	"bytes"
	"fmt"
	"io"
	"os/exec"
)

func main() {
	// 设置shell管道
	cmd := exec.Command("echo", "-n", "zhanghongbin01")
	// 获取到输出管道
	out, err := cmd.StdoutPipe()
	if err != nil {
		fmt.Println("Get output pipe error")
		return
	}

	// 开始命令
	if err := cmd.Start(); err != nil {
		fmt.Println("Exec command error")
		return
	}

	// 读取输出
	var result bytes.Buffer
	for {
		temp_buf := make([]byte, 5)
		n, err := out.Read(temp_buf)
		if err != nil {
			if err == io.EOF {
				break
			}
			fmt.Println("Read result error")
		}

		// 如果读到了数据，则放到输出区域里面
		if n > 0 {
			result.Write(temp_buf[:n])
		}
	}

	// 输出命令的执行结果
	fmt.Println(result.String())
}
