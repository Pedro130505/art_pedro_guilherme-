#include <windows.h>
#include <stdio.h>


int main()

{
	HANDLE hDesbloqExib = OpenEvent(EVENT_ALL_ACCESS, FALSE, TEXT("Desbolqueia exib"));
	HANDLE hTermExib = OpenEvent(EVENT_ALL_ACCESS, FALSE, TEXT("Termina"));


	if (hDesbloqExib == NULL || hTermExib == NULL) {
		printf("Erro ao abrir evento! Codigo = %d\n", GetLastError());
		return 1;
	}

}