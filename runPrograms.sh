#!/usr/bin/bash
curpwd=$(pwd)



echo "-----Run Programs----"
echo "Choose option:"
echo "1. Stack"
echo "2. Queue"
echo "3. Unique pointer"
echo "4. String Functions"
echo "5. Priority Queue"

runPrograms()
{
    read -p "Enter option: " option
    case $option in
    1)
        echo "Stack::"
        cd STL/Stack;
        showBuildOptions
        ;;
    2)
        echo "Queue::"
        cd STL/Queue;
        showBuildOptions
        ;;
    3)
        echo "Unique Pointer"
        ;;
    4)
        echo "String Functions"
        ;;
    5)
        echo "Priority Queue::"
        cd STL/PriorityQueue;
        showBuildOptions
        ;;
    *)
        echo "Invalid Option, try again..."
        runPrograms
        ;;
    esac 
}

showBuildOptions()
{
    echo "Build options:"
    echo "1. Clean build"
    echo "2. build and run"
    echo "3. Clean and build run"
    echo "4. Do nothing"

    read -p "Enter option no. " option
    case $option in
    1)
        echo "Clean build"
        make clean;
        ;;
    2)
        echo "Build and Run"
        make install;
        ./app_static.exe;
        ;;
    3)
        echo "Clean and build run"
        make clean;
        make install;
        ./app_static.exe;
        ;;
    4)
        echo "Do nothing"
        ;;
    5)
        echo "Invalid option, try again.."
        showBuildOptions
        ;;
    esac
}



runPrograms

