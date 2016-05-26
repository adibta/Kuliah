//Menghitung fungsi f(x)
//function [f] = hasilf(A,x)
//A merupakan vektor kolom yang memenuhi kriteria
//[A0 A1 A2 A3 ... An]
//untuk fungsi f(x) = A0*x^0 + A1*x^1 + A2*x^2 + A3*x^3 + An*x^n
//x merupakan nilai x
function [f] = hasilf(A,x)
    n = size(A,"c")
    for w = 1:n
        v(w)= x^(w-1)
    end
    f = A*v
endfunction
