
object session
{
  
  def sqrt(x: Double) = 
  {
     def abs(x: Double) = if (x < 0) -x else x

     def sqrtIter(guess: Double) : Double =
       if(isGoodEnough(guess)) guess
       else sqrtIter(improve(guess))

     def isGoodEnough(guess: Double) : Boolean= 
       abs(guess * guess - x) < (0.001 * x)

     def improve(guess: Double) : Double = 
       (guess + x/guess) / 2

     // call 
     sqrtIter(1.0)
  }


  def main(args: Array[String]) : Unit = 
  {
    println("sqrt(4) = " + sqrt(4))
    println("sqrt(1e-60) = " + sqrt(1e-60))
    println("sqrt(1e60) = " + sqrt(1e60))

  }

}
