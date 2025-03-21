# Алгоритм поиска самого короткого пути до всех вершин
Does as the name states

Поддерживает поиск в глубину и в ширину
## Сборка
### Linux
Нужно заранее иметь на компьютере cmake, make, git и компилятор C++
#### Debug
```
git clone https://github.com/roffio/vk_maps.git && cd vk_maps && mkdir build && cd build && cmake .. && make
```
#### Release
```
git clone https://github.com/roffio/vk_maps.git && cd vk_maps && mkdir build && cd build && cmake -DCMAKE_BUILD_TYPE=release ..  && make
```
### Windows 
Нужно заранее иметь на компьютере cmake, git и компилятор C++
#### Debug
```
git clone https://github.com/roffio/vk_maps.git
cd vk_maps
mkdir build
cd build
cmake ..
cmake --build .
```
#### Release
```
git clone https://github.com/roffio/vk_maps.git
cd vk_maps
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config release
```

_Или скачайте скомпилированную версию_
## Использование
Предварительно найдите исполяемый файл
```
./vk_maps [Путь к документу]
```
Документ должен иметь структуру
* Первая строка - количество вершин
* Вторая строка - количество ребер в графе
* Далее идут рёбра графа ("0 1" означает, что существует путь от вершины с номером 0 до вершины с номером 1)
* Длина каждого ребра равна 1
* Последняя строка - номер вершины, от которой необходимо посчитать расстояние до всех остальных
* Нумерация вершин всегда начинается с нуля
* Допускается, что путь до каждой вершины существует


## Пример использования
```
[roffio@archlinux vk_maps]$ /home/roffio/Downloads/vk_maps/out/build/main_gcc/vk_maps /home/roffio/Downloads/vk_maps/tests/test1.txt
1
2
3
3
0
```
