#pragma once

namespace ft
{
    // ! enable_if
    // * the general type is selected in case of the condition is false
    // * and since it doesn't specify the type, so the type of argument 
    // * declared with type will cause a SFINAE
    template <bool Cond, class T = void>
    struct enable_if
    {
    };

    // * specialization for true, in case of true the type is selected
    // * in case of int for example the type is setted to int
    template <class T>
    struct enable_if<true, T>
    {
        typedef T type;
    }; 
} 


