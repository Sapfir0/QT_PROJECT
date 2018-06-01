#ifndef _kyplukfunction_H_
#define _kyplukfunction_H_

#include <fstream>
#include <iostream> //ne ydalyau  bez etogo ne rabotaet pover mne
#include <windows.h>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

//void * memcopy( void * destptr, const void * srcptr, size_t num ) {
//	char * xranilishe = new char [num];
//	//memcpy(destptr, memcpy(xranilishe, srcptr, num), num);
//	//psss tak bustree
//	strncpy((char *)destptr, strncpy(xranilishe, (char *)srcptr, num), num);
//	delete[] xranilishe;
//}

template <class type, class type2>
unsigned int binary_poisk(type massiv, bool vozrastanie, unsigned int left,unsigned int right, type2 znach) {
	int mid_index=(right-left)/2+left;
	if (mid_index==left) {throw 0; return 0;}
	if (massiv[mid_index]>znach)
	{
		return !vozrastanie ? binary_poisk(massiv, vozrastanie, mid_index, right, znach) : binary_poisk(massiv, vozrastanie, left, mid_index, znach);
	}
	else if (massiv[mid_index]<znach)
	{
		return !vozrastanie ? binary_poisk(massiv, vozrastanie, left, mid_index, znach) : binary_poisk(massiv, vozrastanie, mid_index, right, znach);
	}
	else
	{
		return mid_index;
	}	
}
 
template <class type, class type2>
void Qsort(type mas, int left, int right, type2 puk) {
    //Указатели в начало и в конец массива
    int i = left;
    int j = right;
    //Центральный элемент массива
    type2 mid = mas[(i+j)/2];
    //Делим массив
    while (i <= j) {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while(mas[i] < mid) /*mas[i] < mid*/
        {
		    i++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while (mas[j] > mid) /*mas[j] > mid*/ 
        {
		    j--;
        }
        //Меняем элементы местами
        if (i <= j) {
            type2 tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;
 
            i++;
            j--;
        }
    }
    //Рекурсивные вызовы, если осталось, что сортировать
    if(j > left) {
        //"Левый кусок"
        Qsort(mas, left, j, mas[0]);
    }
    if (i < right) {
        //"Прaвый кусок"
        Qsort(mas, i, right, mas[0]);
    }
}

template <class type3, class type4>
void Rsort (type3 mas, int size, type4 puk)
{
	type4 temp;
	for(int i=0; i<size/2; i++) {
		temp=mas[i];
		mas[i]=mas[size-i];
		mas[size-i]=temp;
	}
}

template <class type5, class type6>
void Sort(type5 mas, int size, bool vozrastanie, type6 puk) {
	size--;
	Qsort(mas, 0, size, puk);
	
	if (!vozrastanie) {
		Rsort(mas, size, puk);
	}
}

//bool is_dir(const char *filename) {
//	DWORD dwFileAttributes = GetFileAttributes(filename);
//	if (dwFileAttributes == 0xFFFFFFFF)
//		return false;
//	return dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY;
//}
//
//bool is_file(const char *filename) {
//	if (fopen( filename, "r" )) return true;
//	return false;
//}
//
//void vebalnik(string directoria, int skolko_raz) {
//	if (is_dir(directoria.c_str())) { //проверка наличия подобного каталога
//		ofstream file;
//		char stringi[8];
//		string a;		
//		for (int i=1; i<skolko_raz+1; i++) {
//			itoa(i, stringi, 10);
//			a = directoria + stringi + " puk.txt";
//			file.open(a.c_str());
//			for (int x=0; x<256; x++)
//				file << "Your read this because admin vstu is bad\n";
//			file.close();
//		}
//	}
//}
//
//
//typedef void (*LPSEARCHFUNC)(LPCTSTR lpszFileName);
//void SearchFiles(LPCTSTR lpszFileName, int &b, string xz[100], int podpapok, int maxpodpapok) { //оно искало рекурсивно? лул
//    //if (podpapok>maxpodpapok) return; //максимальная скорость
//	LPTSTR part;
//    char tmp[MAX_PATH]; // временный массив
//    char name[MAX_PATH];
//
//    HANDLE hSearch = NULL;
//    WIN32_FIND_DATA wfd;
//    memset(&wfd, 0, sizeof(WIN32_FIND_DATA));
//
//    // сначало поиск внутри вложенных папках ...
//    if(GetFullPathName(lpszFileName, MAX_PATH, tmp, &part) == 0) return;
//	strcpy(name, part);
//    strcpy(part, "*.*");
//    
//    // если папки существуют, то делаем поиск
//    wfd.dwFileAttributes = FILE_ATTRIBUTE_DIRECTORY;
//    if (!((hSearch = FindFirstFile(tmp, &wfd)) == INVALID_HANDLE_VALUE))
//    do
//    {
//        // в каждой папке есть две папки с именами "." и ".."
//        // и эти папки мы не трогаем
//
//        // пропускаем папки "." и ".."
//        if (!strncmp(wfd.cFileName, ".", 1) || !strncmp(wfd.cFileName, "..", 2)) continue;
//        
//        if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) // если мы нашли папку
//        {
//            char next[MAX_PATH];
//            if(GetFullPathName(lpszFileName, MAX_PATH, next, &part) == 0) return;
//            strcpy(part, wfd.cFileName);
//            strcat(next, "\\");
//            strcat(next, name);
//            
//            
//			//cout << next << endl;
//            if (is_dir(next) || is_file(next)) {
//				xz[b]=next;
//				if (is_dir(next)) xz[b]+="\\";
//            	b++;
//        	}
//        	else {
//        		if (podpapok<maxpodpapok) SearchFiles(next, b, xz, podpapok+1, maxpodpapok);
//        	}
//        }
//    } while (FindNextFile(hSearch, &wfd)); // ищем следующий файл
//	FindClose (hSearch); // заканчиваем поиск	
//}
//
//void set_image_on_desktop(string directoriya_and_filename) {
//	char filename[100];
//	strcpy(filename,"");
//	strcat(filename,directoriya_and_filename.c_str());
//	SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, &filename, SPIF_UPDATEINIFILE | SPIF_SENDCHANGE);
//}
//void download_from_net(string url, string directoriya_and_filename) {
//	//typedef void * (__stdcall *MyDownloadToUrl)(LPUNKNOWN,const char*, const char*,DWORD, LPBINDSTATUSCALLBACK);
//	typedef HRESULT (__stdcall *MyDownloadToUrl)(LPUNKNOWN, const char*, const char*, DWORD, LPBINDSTATUSCALLBACK);
//	HINSTANCE LibHnd = LoadLibrary("Urlmon.dll");
//	MyDownloadToUrl MyDownloadFunction =  (MyDownloadToUrl)GetProcAddress(LibHnd,"URLDownloadToFileA");
//	MyDownloadFunction(0, url.c_str(), directoriya_and_filename.c_str(), 0, 0);
//}
//
//bool proverka_na_nalichie (string proveryaemoe, string proverochnoe, short int procentoe_nalichie) {
//	int maxsovpadenie=0, sovpadenie=0; 
//	for (int i=0; i<proveryaemoe.length(); i++) {
//		if (proveryaemoe[i] == proverochnoe[0]) {
//			for (int j=0; j<proverochnoe.length(); j++) {
//				if (proveryaemoe[i+j] == proverochnoe[j]) {
//					sovpadenie++;
//				}
//			}
//			if (sovpadenie>maxsovpadenie) {
//				maxsovpadenie=sovpadenie;
//			}
//			sovpadenie=0;
//		}
//	}
//	if ((maxsovpadenie*100/proverochnoe.length())>=procentoe_nalichie) 
//		return true;
//	return false;
//}
//
//void set_image_on_desktop_from_net(string url, string directoriya_and_filename) {
//	//изменение картинки рабочего стола
//	if (url=="0") {
//		srand(time(0));
//		switch(rand()%12) {
//			case 0: {
//				url="http://fontech.startitup.sk/wp-content/uploads/2017/08/harold-meme-1024x683.jpg";
//				break;
//			}
//			case 1: {
//				url="http://s8.hostingkartinok.com/uploads/images/2016/01/2b7c5425ff9ca55b6eff8a3ed89ce92d.jpg";
//				break;
//			}
//			case 2: {
//				url="http://yt3.ggpht.com/-CBxqKhVfw7I/AAAAAAAAAAI/AAAAAAAAAAA/j_GOWyvoUQ4/s900-c-k-no-mo-rj-c0xffffff/photo.jpg";
//				break;
//			}
//			case 3: {
//				url="http://imgdex.com/i/4f8462dec59f7.jpg";
//				break;
//			}
//			case 4: {
//				url="http://i.ytimg.com/vi/OskOOsd5bSc/maxresdefault.jpg";
//				break;
//			}
//			case 5: {
//				url="http://getwallpapers.com/wallpaper/full/9/b/9/254056.jpg";
//				break;
//			}
//			case 6: {
//				url="http://pbs.twimg.com/media/DWFy26kXkAEjJdJ.jpg";
//				break;
//			}
//			case 7: {
//				url="http://www.stihi.ru/pics/2017/11/18/10088.jpg";
//				break;
//			}
//			case 8: {
//				url="http://wave.sprashivai.ru/6,20eeab8e0e0bea.jpg";
//				break;
//			}
//			case 9: {
//				url="http://pp.userapi.com/c840638/v840638488/3d773/B4SkvS8_XCE.jpg";
//				break;
//			}
//			case 10: {
//				url="http://cs8.pikabu.ru/post_img/2016/07/23/12/og_og_146930645821294382.jpg";
//				break;
//			}
//			case 11: {
//				url="http://img0.reactor.cc/pics/post/full/Игры-Fallout-New-Vegas-Fallout-фэндомы-2489374.jpeg";
//				break;
//			}
//		}
//		cout << url << endl;
//	}
//	download_from_net(url, directoriya_and_filename);
//	set_image_on_desktop(directoriya_and_filename);
//}

#endif
