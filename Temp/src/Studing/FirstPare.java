package Studing;

public class FirstPare implements StudentAction {
    private int sleepTime;
    private  double wish;

    public FirstPare(int sleepTime,double wish) {
        this.sleepTime = sleepTime;
        this.wish= wish;
    }

    @Override
    public void move() {
        double res;
        if((res=this.sleepTime*this.wish)<2){
            System.out.println("Братан, надо посспать");
        }
        else System.out.println("Вейк вейки, итс тайм фо скул");

    }
}
