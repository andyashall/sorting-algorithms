package main

import (
  "fmt"
  "math/rand"
)

func bubble(list []int) []int {
  for n := len(list) -1; n >= 0; n-- {
    for i := 0; i < len(list) -1; i++ {
      if list[i] > list[i + 1] {
        list[i], list[i+1] = list[i+1], list[i]
      }
    }
  }
  return list
}

func selection(list []int) []int {
  for n := len(list) - 1; n >= 0; n-- {
    larg := 0
    for i := 0; i < n; i++ {
      if list[i] > list[larg] {
        larg = i
      }
    }
    list[n], list[larg] = list[larg], list[n]
  }
  return list
}

func insertion(list []int) []int {
  for n := 1; n < len(list); n++ {
    c := list[n]
    p := n
    for p > 0 && list[p-1] > c {
      list[p] = list[p-1]
      p--
    }
    list[p] = c
  }
  return list
}

func mean(list []int) int {
  var o int
  for i := 0; i < len(list); i++ {
    o = o + list[i] 
  }
  return o / len(list)
}

func main() {
  var list []int
  for i := 0; i < 10000; i++ {list = append(list, rand.Intn(10000))}
  sorted := bubble(list)
  // mean := mean(list)
  fmt.Println(mean)
}