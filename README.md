# CG_Labyrinth
Задание по курсу Компьютерной Графики ВМК МГУ (3 курс, 2021г)

# Управление
• WASD - перемещение
• ESC - выход из игры
# Цель игры
Цель игры - выбраться из лабиринта, состоящего из комнат с ловушками.
#  Дизайн лабиринта и комнат
Представленный в репозитории лабиринт состоит из 22 разных комнат.
Предполагается, что лабиринт можно считать в двумерных массив размером
10x10 комнат.
В центре каждой комнаты нарисована буква, состоящая из ловушек. Ловушки
так же встречаются рядом с выходами из комнат.
Ловушками являются шипы и огонь, наступив на которые (на половину тайла)
персонаж погибает. Они анимированы, анимация огня занимает 4 фрейма, шипов - 8.
Самой первой комнатой, в которую попадает игрок, всегда будет комната Е,
считываемая из файла E.txt (названия файлов комнат соответствуют буквам в
центре комнат)
Чтобы выйти из лабиринта и завершить игру, нужно найти комнату с сундуком и до
него дойти. Сундук анимирован, анимация из 8 фреймов.
# Персонаж
Персонаж может перемещаться в произвольном направлении. При смене
направления влево/вправо спрайт персонажа поворачивается в ту сторону, куда
движется. Спрайт анимирован, постоянно происходит смена кадров (4 шт).
#Игровой процесс
После смерти персонажа или победы появляются соответствующие экраны. Чтобы
выйти из игры, игроку нужно нажать ESC.