package test

import (
    "io/ioutil"
    "net/http"
    "fmt"
)

func main(){
  resp, _ := http.Get("http://book.douban.com/subject/26416401/")
  defer resp.Body.Close()
  body, _ := ioutil.ReadAll(resp.Body)
  fmt.Printf("%s", body)
}

// func main() {
//   resp, err := http.Get("http://book.douban.com/subject/26416401/")
//   if err != nil {
//     panic(err)
//   }

//   defer resp.Body.Close()
//   body, err := ioutil.ReadAll(resp.Body)
//   // resp.Body.Close()
//   if err != nil {
//     panic(err)
//   }
//   fmt.Printf("%s", body)
// }

