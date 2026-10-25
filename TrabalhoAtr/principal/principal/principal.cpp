#include <windows.h>
#include <stdio.h>
#include <conio.h>
#define ESC 0x1B

HANDLE hDesbloqSup, hTermSup;
HANDLE hDesbloqPCP, hTermPCP;
HANDLE hDesbloqRet, hTermRet;
HANDLE hDesbloqExib, hTermExib;
HANDLE hDesbloqGest, hTermGest;

int tecla; 

int main()


{
	STARTUPINFO siExib, siGest;
	PROCESS_INFORMATION piExib, piGest;

	ZeroMemory(&siExib, sizeof(siExib)); siExib.cb = sizeof(siExib);
	ZeroMemory(&siGest, sizeof(siGest)); siGest.cb = sizeof(siGest);

	TCHAR cmdExib[] = TEXT("exibicao.exe");
	TCHAR cmdGest[] = TEXT("gestao.exe");

	BOOL ok; 

	ok = CreateProcess(NULL, cmdExib, NULL, NULL, FALSE, 0, NULL, NULL, &siExib, &piExib);

	if (!ok) {
		printf("Erro ao criar processo exibicao.exe! Codigo = %d\n", GetLastError());
	};

	ok= CreateProcess(NULL, cmdExib, NULL, NULL, FALSE, 0, NULL, NULL, &siGest, &piGest);

	if (!ok) {
		printf("Erro ao criar processo gestao.exe! Codigo = %d\n", GetLastError());
	}

	printf("Principal rodando. Tecle algo para encerrar os filhos...\n");


	void Alterna(HANDLE hEvento, bool &rodando, const char *nome);
    {

		rodando = !rodando; 
		if (rodando) {
			SetEvent(hEvento);
			printf("%s: desbloqueado\n", nome);
		}
		else {
			ResetEvent(hEvento);
			printf("%s: bloqueado\n", nome);
		})
	
	}

	bool rodSup = true, rodPCP = true, rodRet = true, rodExib = true, rodGest = true;

	tecla = _getch();

	switch (tolower(tecla)) {
		case '1':
			Alterna(hDesbloqSup, rodSup, "Supervisor");
			break;
		case '2':
			Alterna(hDesbloqPCP, rodPCP, "PCP");
			break;
		case '3':
			Alterna(hDesbloqRet, rodRet, "Retaguarda");
			break;
		case '4':
			Alterna(hDesbloqExib, rodExib, "Exibição");
			break;
		case '5':
			Alterna(hDesbloqGest, rodGest, "Gestão");
			break;
	} while (tecla != ESC);

	// Se ESC true Termina os eventos

	SetEvent(hTermSup);
	SetEvent(hTermPCP);
	SetEvent(hTermRet);
	SetEvent(hTermExib);
	SetEvent(hTermGest);

	WaitForSingleObject(piExib.hProcess, INFINITE);
	WaitForSingleObject(piGest.hProcess, INFINITE);
	CloseHandle(piExib.hThread);
	CloseHandle(piGest.hThread);


	// Desbloqueia todos os eventos de sincronização
	hDesbloqExib = CreateEvent(NULL, TRUE, TRUE, TEXT("Desbolqueia sup"));
	hDesbloqGest = CreateEvent(NULL, TRUE, TRUE, TEXT("Desbolqueia sup"));
	hDesbloqPCP = CreateEvent(NULL, TRUE, TRUE, TEXT("Desbolqueia sup"));
	hDesbloqRet = CreateEvent(NULL, TRUE, TRUE, TEXT("Desbolqueia sup"));
	hDesbloqSup = CreateEvent(NULL, TRUE, TRUE, TEXT("Desbolqueia sup"));


	//Termina todos os eventos de sincronização
	hTermExib = CreateEvent(NULL, TRUE, FALSE, TEXT("Termina sup"));
	hTermGest = CreateEvent(NULL, TRUE, FALSE, TEXT("Termina sup"));
	hTermPCP = CreateEvent(NULL, TRUE, FALSE, TEXT("Termina sup"));
	hTermRet = CreateEvent(NULL, TRUE, FALSE, TEXT("Termina sup"));
	hTermSup = CreateEvent(NULL,TRUE, FALSE, TEXT("Termina sup"));


} 








