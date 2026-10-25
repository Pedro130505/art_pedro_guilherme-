#include <windows.h>
#include <stdio.h>


int main()

{
	HANDLE hDesbloqGest = OpenEvent(EVENT_ALL_ACCESS, FALSE, TEXT("Desbolqueia Gestao"));
	HANDLE hTermGest = OpenEvent(EVENT_ALL_ACCESS, FALSE, TEXT("Termina Gestao"));


	if (hDesbloqGest == NULL || hTermGest == NULL) {
		printf("Erro ao abrir evento! Codigo = %d\n", GetLastError());
		return 1;
	}

}