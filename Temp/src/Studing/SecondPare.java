package Studing;

public class SecondPare implements StudentAction{
    private int sleepTime;
    private  double wish;

    public SecondPare(int sleepTime,double wish) {
        this.sleepTime = sleepTime;
        this.wish= wish;
    }
    @Override
    public void move() {
        double res;
        if((res=this.sleepTime*this.wish)<1.5){
            System.out.println("Братан, надо посспать, ты все еще мертв");
        }
        else System.out.println("Вейк вейки, итс тайм фо скул, уже вторая параа!!!!!");

    }
}
