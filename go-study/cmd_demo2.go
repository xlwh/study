package main

import (
	"os/exec"
)

func main() {
	cmd1 := exec.Command("ps", "aux")
	cmd2 := exec.Command("grep", "test")

}
