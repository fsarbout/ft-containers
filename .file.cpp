// # QUESTIONS.md

// ? ## 1 -  why do we need iterators ?

// * easy to work with , I can use iterator for a container without knowing the structure of container.
// * iterators reduce the complexity and execution time of program.
// * facilitate accessing, editing and  performing operators on container elements
// * they connect the algorithm with the container.
// * work with different containers, need to add operator overload if logic is different
// * STL is based on the separation of data and operations , iterators are the bridge between them.

// ? ## 2 -  what is iterator traits ?

// * class provides information about iterator so that the algorithm can know which methods it has to apply on that container.
// * we use it in reverse_iterator, reverse_iterator works only with bidirectional and random access iterators, and it has to ensure that it one of them.

// ? # what is iterator category ?

// ? # what is iterator category tag ?

// * empty class, it is just a name that defines is ${iterator_category}_tag.
// * to know how we could deal with the iterator, (if it should provide only methods for input iterator for example it has to be input_iterator_tag, helps also with algorithms)

// ? # what is reverse iterator ? why do we need it ? we can easily use begin() instead of rend()?


* 

// ? # returning this vs *this vs this.ptr ...
// ? # why do we need const_iterator and iterator ?
// ? # why do we need const ??
// ? # what is std::pair , std::make_pair ?
// ? # what is equal ?
// ? # what is lexicographical_compare ?
// ? # when do we need const ?
// ? # what is typedef ? typename ? template templaet ? type template ?...
// ? # what is enum ?
// ? # what did I did in every vector method and what is the behavior of every single one?
// ? # how could that we are using random iterator and defining vector constructor with a type of InputIterator ? 
// ? # what is explicit ?
// ? # why do we declare template fucntions inside template class ?
// ? # what is template template parameter ?
// ? # <>::<> syntax ?
// ? # allocator methods and how are they working ?
// ? # destroy ?
// ? # the fucking address and references ???!!!
// ? # test with debugger and check values .
// ? # pragme once &&  pre processing 

// ? # typedef typename ?
// * typename : telling the compiler that the template parameter is a type.
// * typedef : define an existing type with a new name.
// * typedef typename _Mybase::value_type value_type;
// * ^^ telling the compiler that _Mybase::value_type is a type and not a variable. so that 
// * the typedef can rely on that fact



// ? pointers ?

// * The compiler will not let you dereference a void* pointer because it does not know the size of the object pointed to.
// * NOTE : (pointers), The address-of operator (&) can only be used on the RHS. ??
// * int *ptr = NULL; >> ptr points to nothing so we cannot dereference it.
// * nullptr exists only in c++11 and above.
// * >> int *numbers; *(numbers+i) is numbers[i] , (numbers) is the same as &numbers[0],
// ** *(numbers+i) is numbers[i].
// * an int typically has 4 bytes. That is (numbers + 1) increases the address by 4.
// * int arr[50], int arr[] is treated as int *arr by compiler. The size of the array given in [] is ignored

// ? references

// * the main use of references is to pass a variable by reference to a function. that way ,
// ** the function will work on the original copy of the variable instead of a clone copy (pass by value).
// ** changes inside function will affect the variable outside the function.
// * references also stores the address of the variable.
// * a reference is kinda dereferenced pointer .
// * we cannot return a reference from a function's local variable. > we are returning the address of a variable
// ** that  will be destroyed once we're are outside this function scope.
// * In pass-by-value, a clone is made and passed into the function. The caller's copy cannot be modified.
// * In pass-by-reference, a pointer is passed into the function. The caller's copy could be modified inside the function.
// * In pass-by-reference with reference arguments, you use the variable name as the argument.
// * In pass-by-reference with pointer arguments, you need to use &varName (an address) as the argument.
// ? references advantages :
// * references are safe to use cuz they are never NULL. (obligation of initializing) + can't be re-assigned (wouldn't be changed by mistake).
// * references are the same variable with another name ,pointers needs extra storage for themselves .
// * thus references are faster than pointers.
// * reference are dereferenced explicitly, less syntax trouble.

// ? new and delete works on pointers
// * new() returns a pointer to the allocated memory for this pointer.
// * delete() takes that pointer as sole argument and frees that memory allocated by new.

// ?  we can't access end() of vector ?
// * it doesn't point to any valid data, doesn't point to last element, it points to the element behind the last,
// ** it's an undefined behavior if we try to access it.
// * v::iterator it = v.end(); >> dereferencing invalid pointer !!!
// * in case of empty vector , begin() == end()

// ? this ? : this->data == (*this).data (combines operator * and -> )
// * *this a
// * for a class X , "this" has type >> (X* this)
// * for a class X , if a method is marked const then >> (const X* this)

// * ((this = 1) !!! ) it's not assignable, it's "PRVALUE" (look at next question)),
// * this is a pointer, and *this is a dereferenced pointer.
// * allocated on the stack -- unless you have specified the return type of the method to return a reference
// * "THIS" : <<<prvalue-expression>>>>,hidden pointer on the object of class passed to all methods (non-static member function)
// * "*THIS" :  <<<lvalue-expression>>>
// ! {
// this vs *this :
// #include <iostream>

// class Foo
// {
// public:
//     Foo()
//     {
//         this->value = 0;
//     }

//     Foo get_copy()
//     {
//         // doesn't increment
//         // here working with (*this) we're working with copy, it's just in function body
//         return *this;
//     }

//     Foo &get_copy_as_reference()
//     {
//         // increments
//         return *this;
//     }

//     Foo *get_pointer()
//     {
//         // increments
//         return this;
//     }

//     void increment()
//     {
//         this->value++;
//     }

//     void print_value()
//     {
//         std::cout << this->value << std::endl;
//     }

// private:
//     int value;
// };

// int main()
// {
//     Foo foo;
//     foo.increment();
//     foo.print_value();

//     foo.get_copy().increment();
//     foo.print_value();

//     foo.get_copy_as_reference().increment();
//     foo.print_value();

//     foo.get_pointer()->increment();
//     foo.print_value();

//     return 0;
// }
// ! }

// ? rvalue ? lvalue ?

// * "LVALUE" we can refer to lvalue as location value to remember tha it has a location in memory.(it's not tmp)
// * lvalue can hold a value. int a = 10; >> a is lvalue.
// * "RVALUE" , it's a tmp value that can be assigned to a lvalue. example : local variable inside a function. they will expire without lvalues
// * references that we use with single "&" are lvalues. there is also reference rvalues that are used like : int &&a = 10;
// * "PRVALUE":  pure right hand value , such as : (10, 'a', "hello world!")
// * we can assign to a function that return an lvalue. example: the "reference" function points to the global_var
// ! { ```
//  int global_var = 10;
//  ``` int &f1() { return global_var; }
//  ``` int f() { return 10; }
//  int main()
//  {
//       f() = 100; // error
//       f() = 100; // fine
//       std::cout << a << std::endl;
// !  }
//  ```
// * lvalue can be implicitly converted to rvalue.
// * we cannot pass a tmp rvalue to a function that takes an lvalue(if it's argument not const, we have to mark it const so that the value pointed to cannot be changed).(invalid conversion)
// ! {
// * ``` "int &a = 1;"
// will not work , modifies that pure rvalue is impossible and meanenless .

// The literal constant 10 is prvalue and would expire, so a reference to it is just meaningless.
//

// * ``` "const int &i = 1;" // working
// because the function's body can't change the const variable. so no problem here.

// when we work with const the compiler do the following :
// * ``` const int& ref = 10;

// ... would translate to:
// * ``` int __internal_unique_name = 10;
// * ``` const int& ref = __internal_unique_name;
// ! }

// ? when should operators return by reference ?
// we return by reference for efficiency (to avoid duplicate copies)
// ******** by reference ********
// ! if the operator is changing the current object then it should return by reference.
// ! return by reference avoids making a copy of the return value.
// * we use references to chain methods together like: obj1.setX(10).setY(20) 
// * if the built-in operator returns an rvalue then your overload should return a reference.
// * we return by value when the operator is not changin the current object
// *
// * When a function returns a reference, it returns an implicit pointer to its return value.
// * This way, a function can be used on the left side of an assignment statement

// ******** by value ********
// * if the built-in returns an lvalue then your overload should return a value.
// lvalue: is an object that is not a temporary object.

// Returning a value also forces unnecessary trips through the object's copy constructor,
//  costing you in performance.?

// ? why do we subract 1 in case of reverse_iterator ?

// ? static function ?

// * static members exist as members of the class rather than as an instance in each object of the class. this is non-static
// * A static member function can be called, even when a class is not instantiated.
// * A static member function cannot have access to the this pointer of the class.

// #include <iostream>
// int &foo()
// {
//     int i = 10;
//     return i;
// }

// int main()
// {
//     std::cout << foo() << std::endl;
// }

// ? destructor ?
// * destroying the object by calling "delete this"

// ? Watch out that if you try to use return *this; on a function whose return type is Type and not Type&,
// ? C++ will try to make a copy of the object and then immediately call the destructor