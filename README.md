# Unix-Programming

## 1. Bash
- Installing vim
```console
sudo apt-get install vim
```

- Using
```console
vim find.sh
```

## 2. C++ GCC or G++
- Installing gcc and g++
```console
sudo apt install gcc
sudo apt install g++
```

- Compiling
```console
g++ -lstdc++fs -std=c++17 -o main *.cpp -lstdc++fs
```
- Running
```console
./main -t find-oldest-dir "/home/bohdan/first"
```

## 3. C++ Qt GUI
- Installing Qt Creator
```console
sudo apt install build-essential
sudo apt install qtcreator
sudo apt install qt5-default
```

## 4. Python
- Installing python and PyCharm
```console
sudo apt update
sudo apt install software-properties-common

sudo add-apt-repository ppa:deadsnakes/ppa

sudo apt install python3.7
```
```console
sudo apt install snapd snapd-xdg-open
sudo snap install pycharm-community --classic
```

## 5. Perl
- Running
```console
perl main.pl --help
perl main.pl --tests
perl main.pl -t find-oldest-dir /home/bohdan/first/
perl main.pl -t delete-repeats /home/bohdan/second .cpp
```

## 6. Java Console
- Installing java and Eclipse
```console
apt-get install default-jdk

sudo apt install default-jre
sudo snap install --classic eclipse
```

- Compiling
```console
javac *.java
```
  
- Running
```console
java program.MainProgram --help
```
If you are compiling and running from program folder please use following line
```console
java -classpath ../ program.MainProgram --help
```

## 8. .NET Core
- Running (in bin/.net core directory)
```console
dotnet DotNetCore.dll --help
```

```console
dotnet DotNetCore.dll -t find-oldest-dir /home/bohdan/first
dotnet DotNetCore.dll -t delete-repeats /home/bohdan/second .cpp
```
