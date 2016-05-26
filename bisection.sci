//Metode bisection 
//function[x] = bisection(A,low,up)
//A merupakan vektor kolom yang memenuhi kriteria
//[A0 A1 A2 A3 ... An]
//untuk fungsi f(x) = A0*x^0 + A1*x^1 + A2*x^2 + A3*x^3 + An*x^n
//low merupakan batas bawah dan up merupakan batas atas
//akar persamaan harus berada diantara batas bawah dan atas
//toleransi error = 0.0000001

function[x] =bisection(A,low,up)
    if hasilf(A,low) * hasilf(A,up)<= 0 
        while %t
            mid = (low+up)/2
            if abs(hasilf(A,mid)) < 0.0000001
                x = mid
                break
             elseif hasilf(A,low)*hasilf(A,mid) < 0
                up = mid
             else 
                low = mid
             end
        end    
    else
        disp("Akar persamaan tidak terdapat pada batas atas dan batas bawah")
    end
endfunction
