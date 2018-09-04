

**Note 1: Higher-Order Functions are a great FP language feature**

If you’re not familiar with the term Higher-Order Function (HOF), it
basically means that 

* (a) you can treat a function as a value ( val ) — just
like you can treat a String as a value — and 
* (b) you can pass that valueinto other functions.

<hr>

**Note 2: Recursion is a by-product**

Sometimes you’ll see a definition of FP that states, “Recursion is a require-
ment of functional programming.” While it’s true that pure FP languages
use recursion, the need for recursion is a by-product of my FP definition.

<hr>

**The Terminology Barrier**

* Things that can be mapped over shall be called ... **Functor**.

* **Combinator** 

    Per the Haskell wiki, this has two meanings, but
    the common meaning is, “a style of organizing
    libraries centered around the idea of combining
    things.” This refers to being able to combine
    functions together like a Unix command pipeline,
    i.e., ps aux | grep root | wc -l
    
* **higher-order** 
    function A function that takes other functions as
    parameters, or whose result is a function

* **Lambda**
    Another word for “anonymous function.”

<hr>

**Call-By-Value vs Call-By-Name**

* Scala uses call-by-value by default, but it switches to call-by-name evaluation if the
parameter type is preceded by =>

```scala
    scala> def loop: Int = loop
    loop: Int
    scala> def first(x: Int, y: Int) = x
    first: (Int,Int)Int
    scala> def constOne(x: Int, y: => Int) = 1
    constOne: (Int,=> Int)Int
    scala> constOne(1, loop)
    unnamed0: Int = 1
    scala> constOne(loop, 2) // gives an infinite loop.
```

**Nested Functions**

* The  functional  programming  style  encourages  the  construction  of  many  small
helper functions.

``` scala
def sqrt(x: Double) = 
{
    def sqrtIter(guess: Double, x: Double : Double = 
    {
        if(isGoodEnough(guess,x)) guess
        else sqrtIter(improve(guess,x),x)
    }
    def isGoodEnough(guess: Double, x: Double) = 
    {
        abs(square(guess) - x) < 0.001         
    }
    sqrtIter(1.0,x)
}
```

**Tail Recursion**

```scala
// tail recursive b/c iterative function 
// calls are executed in a constant space 
def gcd(a: Int, b: Int) : Int = if (0 == b) a else gcd(b,a%b)
```

```scala
// not tail-recursive because the space needed
// to perform calculations is proportional 
// to input parameter 
def factorial(n: Int) : Int = if(0 == n) 1 else n * factorial(n - 1)
```
