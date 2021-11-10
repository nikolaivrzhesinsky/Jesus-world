package Studing;

import java.io.BufferedReader;
import java.io.InputStreamReader;

//лютая фигня на коленке
public class Menu {
    public static void main(String[] args) {
        BufferedReader reader= new BufferedReader(new InputStreamReader(System.in));


        try {
            System.out.println( "Введите название дисциплины в формате (1я пара) ");
            String pares= reader.readLine();
            System.out.println("Введите продолжительность сна в часах");
            int hours=Integer.parseInt(reader.readLine());
            System.out.println("Введите желание идти на пару в процентном эквиваленте");
            double wishes=Double.parseDouble(reader.readLine());
            switch (pares){
                case "1я":{

                    FirstPare obj1= new FirstPare(hours,wishes);
                    obj1.move();
                    break;
                }
                case "2я":{
                    SecondPare obj2= new SecondPare(hours,wishes);

                    obj2.move();
                    break;
                }
                default:{
                    System.out.println("Таких пар нет или ошибка ввода");
                    break;
                }
            }
        }
        catch (Exception e){
            System.out.println(e.getMessage());
        }

    }
}
