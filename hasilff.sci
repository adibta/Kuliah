//Menghitung fungsi turunan f(x)
//function [f] = hasilff(A,x)
//A merupakan vektor kolom yang memenuhi kriteria
//[A0 A1 A2 A3 ... An]
//untuk fungsi f(x) = A0*x^0 + A1*x^1 + A2*x^2 + A3*x^3 + An*x^n
//x merupakan nilai x
//hanya berlaku untuk fungsi biasa

function [f] = hasilff(A,x)
    n = size(A,"c")
    x2 = A(2:n)
    for w = 1:n-1
        v(w)= x^[w-1]
        x2(w) = x2(w)*w
    end
    f = x2*v
endfunction
