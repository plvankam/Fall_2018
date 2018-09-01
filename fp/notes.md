
<hr>
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

* Things that can be mapped over shall be called ... Functor.

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

* lambda 
    Another word for “anonymous function.”

<hr>


