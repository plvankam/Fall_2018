
object factorial
{
  

  def fact(n: Int): Int = {
    def loop(acc: Int, n: Int): Int =
      if(0 == n) acc
      else loop(acc * n, n -1)
    loop(1,n)
  }

  def main(args: Array[String]) : Unit = 
  {
    println("fact(9) = " + fact(9))
    println("fact(8) = " + fact(8))
    println("fact(7) = " + fact(7))
    println("fact(6) = " + fact(6))
    println("fact(5) = " + fact(5))
    println("fact(4) = " + fact(4))
    println("fact(3) = " + fact(3))
    println("fact(2) = " + fact(2))
    println("fact(1) = " + fact(1))
    println("fact(1000) = " + fact(1000))

  }

}
