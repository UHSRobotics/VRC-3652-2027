class Elevator {
  public:
    Elevator();
    void elevator_movement(float change, float speed);

  private:
      float setpoint;
      float previous_change;
};