
jQuery
======

```javascript
$(this).ready(function(){
    // jQuery methods go here   
});
```

**Selectors**

* $("p")       element selector

* $("#test")   id selector     

* $(".test")   class selector 


```javascript 
yntax   Description     Example
$("*")  Selects all elements    
$(this)     Selects the current HTML element    
$("p.intro")    Selects all <p> elements with class="intro"     
$("p:first")    Selects the first <p> element   
$("ul li:first")    Selects the first <li> element of the first <ul>    
$("ul li:first-child")  Selects the first <li> element of every <ul>    
$("[href]")     Selects all elements with an href attribute     
$("a[target='_blank']")     Selects all <a> elements with a target attribute value equal to "_blank"    
$("a[target!='_blank']")    Selects all <a> elements with a target attribute value NOT equal to "_blank"    
$(":button")    Selects all <button> elements and <input> elements of type="button"     
$("tr:even")    Selects all even <tr> elements  
$("tr:odd")     Selects all odd <tr> elements
```


**Including jQuery and functions**

```html
<head>
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js">
</script>
<script src="my_jquery_functions.js"></script>
</head> 
```

**Events**

* Mouse Events
 
* Keyboard Events

* Form Events

* Document/Window Events

```html
$("p").click(function(){
    // action goes here  
});
```
