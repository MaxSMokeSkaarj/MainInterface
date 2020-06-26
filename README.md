Относительно бесполезная программа на С++, моя первая програма на этом яп.
## Инструкция:
 ### * nix:
   Убедитесь что компилятор установлен: `gcc --version`. Если компилятор не стоит, то:
   * Для диструбтивов, основаных на Debian: `sudo apt install gcc`.
   * Для Archlinux и основаных на нем: `sudo pacman -S base-devel`.
   * Для Rhel(Fedora, centos и т.п): `sudo yum install gcc`.
   * Для Void: `xbps-install gcc`.<br>
   Чтобы скомпилировать исходный код просто запустите `./build`.
 ### MacOS
   * Установите компилятор из brew или macports.<br/>
   Для компиляции запустите `./build CC=clang CXX=clang++ LD=ld.lld`
 ### FreeBSD
   Чтобы скомпилировать, введите `./build CC=clang CXX=clang++ LD=ld.lld`
 ### Windows
   * Убедитесь что компилятор установлен: `gcc --version`. Если компилятор не установлен, то вот [гайд](https://programforyou.ru/poleznoe/kak-ustanovit-gcc-dlya-windows).<br>
   Для компиляции запустите `build.bat`.<br/>
   
Спасибо [Алексею Дебрскому](https://t.me/debrsky) [Артёму Худякову](https://t.me/bruhLinkToMe) за дополнение
