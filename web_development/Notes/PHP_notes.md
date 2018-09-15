PHP Notes 
=========

**Arrays**

* Defining a one-dimensional array
```php
    $team = array('Bill', 'Mary', 'Mike', 'Chris', 'Anne');
```

* Defining a two-dimensional array
```php
    <?php
    $oxo = array(array('x', ' ', 'o'),
    array('o', 'o', 'x'),
    array('x', 'o', ' '));
    ?>
```

**Comparison operators**

Operator Description

    == Is equal to $j == 4
    
    != Is not equal to $j != 21
    
    > Is greater than $j > 3
    
    $j < 100
    
    < Is less than
    
    >= Is greater than or equal to $j >= 15
    
    <= Is less than or equal to
    
    $j <= $k
    


**Logical operators**

Operator Description

    && And
    Example
    $j == 3 && $k == 2
    and Low-precedence and $j == 3 and $k == 2
    || Or
    $j < 5 || $j > 10
    or Low-precedence or
    $j < 5 or $j > 10
    ! Not
    ! ($j == $k)
    xor Exclusive or
    $j xor $k


**Multiline echo statement**
```php
    <?php
    $author = "Brian W. Kernighan";
    echo <<<_END
    Debugging is twice as hard as writing the code in the first place.
    Therefore, if you write the code as cleverly as possible, you are,
    by definition, not smart enough to debug it.
    - $author.
    _END;
    ?>
```
> It is important to remember that the closing _END; tag must appear right at the start
> of a new line and it must be the only thing on that line—not even a comment is
> allowed to be added after it


**Constants**

```php
    define("ROOT_LOCATION", "/usr/local/www/");
```

**Predefined Constants**

> \__LINE__ The current line number of the file.
> 
> \__FILE__ The full path and filename of the file. If used inside an include , the name of the included file is
> returned. In PHP 4.0.2, __FILE__ always contains an absolute path with symbolic links resolved,
> whereas in older versions it might contain a relative path under some circumstances.
> 
> \__DIR__ The directory of the file. If used inside an include , the directory of the included file is returned. This
> is equivalent to dirname(__FILE__) . This directory name does not have a trailing slash unless it is
> the root directory. (Added in PHP 5.3.0.)
> 
> \__FUNCTION__ The function name. (Added in PHP 4.3.0.) As of PHP 5, returns the function name as it was declared
> (case-sensitive). In PHP 4, its value is always lowercase.
> 
> \__CLASS__ The class name. (Added in PHP 4.3.0.) As of PHP 5, returns the class name as it was declared (case-
> sensitive). In PHP 4, its value is always lowercased.
> 
> \__METHOD__ The class method name. (Added in PHP 5.0.0.) The method name is returned as it was declared (case-
> sensitive).
> 
> \__NAMESPACE__ The name of the current namespace (case-sensitive). This constant is defined at compile time. (Added in
> PHP 5.3.0.)

**Precedence of PHP operators** (high to low)

    Operator(s) Type
    () Parentheses
    ++ -- Increment/decrement
    ! Logical
    * / % Arithmetic
    + - . Arithmetic and string
    << >> Bitwise
    < <= > >= <> Comparison
    == != === !== Comparison
    & Bitwise (and references)
    ^ Bitwise
    | Bitwise
    && Logical
    || Logical
    ? : Ternary
    = += -= *= /= .= %= &= != ^= <<= >>= Assignment
    and Logical
    xor Logical
    or Logical


**Operator associativity**

    CLONE NEW Create a new object None
    < <= >= == != === !== <> Comparison None
    ! Logical NOT Right
    ~ Bitwise NOT Right
    ++ -- Increment and decrement Right
    (int) Cast to an integer Right
    (double) (float) (real) Cast to a floating-point number Right
    (string) Cast to a string Right
    (array) Cast to an array Right
    (object) Cast to an object Right
    @ Inhibit error reporting Right
    = += -= *= /= Assignment Right
    .= %= &= |= ^= <<= >>= Assignment Right
    ubtraction and negation Left
    * Multiplication Left
    / Division Left
    % Modulus Left
    . String concatenation Left
    << >> & ^ | Bitwise Left
    ?: Ternary Left
    || && and or xor Logical Left
    , Separator Left




**PHP's cast types**

    (int) (integer) Cast to an integer by dropping the decimal portion
    (bool) (boolean) Cast to a Boolean
    (float) (double) (real) Cast to a floating-point number
    (string) Cast to a string
    (array) Cast to an array
    (object) Cast to an object


