//Metode Newton Raphson 
//hasilf.sci harap diload terlebih dahulu
//hasilff.sci harap diload terlebih dahulu
//function[x] = newtonRaphson(A,x1)
//A merupakan vektor kolom yang memenuhi kriteria
//[A0 A1 A2 A3 ... An]
//untuk fungsi f(x) = A0*x^0 + A1*x^1 + A2*x^2 + A3*x^3 + An*x^n
//x1 merupakan nilai x awal , skalar , bebas
//toleransi error = 0.0000001

function[x] =newtonRaphson(A,x1)
    while %t
        x2 = x1 -(hasilf(A,x1)/hasilff(A,x1))
        if abs(hasilf(A,x2)) < 0.0000001
            x = x2
            break
        end
        x1 = x2
    end
endfunction
