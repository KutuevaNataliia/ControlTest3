// ControlTest3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    int z = 3;
    int y = 3;
    for (int j = 0; j < 17; j++) {
        if (j % 4 == 1)
            continue;
        if (j == z)
            z += 3;
        else if (j == y)
            y *= 3;
    }

    std::cout << "Original: " << z << ' ' << y << std::endl;

    z = 3;
    y = 3;
    __asm {
        mov edi, z
        mov eax, y
        mov esi, 3
        xor ecx, ecx
        Repeat:
            cmp ecx, 17
            je Finish
            mov ebx, 3
            and ebx, ecx
            cmp ebx, 1
            je IncCounter
            cmp ecx, edi
            jnz MulY
            add edi, esi
            jmp IncCounter
        MulY:
            cmp ecx, eax
            jnz IncCounter
            imul esi
        IncCounter:
            inc ecx
            jmp Repeat
        Finish:
            mov z, edi
            mov y, eax
    }

    std::cout << "My: " << z << ' ' << y << std::endl;
}
