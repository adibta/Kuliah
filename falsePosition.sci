//Metode falsePosition 
//function[x] = falsePosition(A,low,up)
//A merupakan vektor kolom yang memenuhi kriteria
//[A0 A1 A2 A3 ... An]
//untuk fungsi f(x) = A0*x^0 + A1*x^1 + A2*x^2 + A3*x^3 + An*x^n
//low merupakan batas bawah dan up merupakan batas atas
//nilai f(up) harus lebih besar dari nol dan
//nilai f(low) harus kurang dari nol
//toleransi error = 0.0000001

function[x] =falsePosition(A,low,up)
    if hasilf(A,low) < 0 & hasilf(A,up) >0 
        while %t
            mid = (low*hasilf(A,up)-up*hasilf(A,low))/(hasilf(A,up)-hasilf(A,low))
            if abs(hasilf(A,mid)) < 0.0000001
                x = mid
                break
             elseif hasilf(A,mid) > 0
                up = mid
             else 
                low = mid
             end
        end    
    else
        disp("Batas bawah atau batas atas tidak memenuhi persyaratan")
    end
endfunction
