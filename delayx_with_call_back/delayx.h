class delayx {
  private:
    unsigned long interval;
    unsigned long previousMillis;
    void (*callback)();  // Function pointer for the callback

  public:
    // Constructor with interval and an optional callback function
    delayx(unsigned long interval, void (*callbackFunc)() = nullptr) {
      this->interval = interval;
      this->callback = callbackFunc;
      this->previousMillis = 0;
    }

    // Check if the delay has finished and call the callback if set
    void update() {
      if (millis() - previousMillis >= interval) {
        previousMillis = millis();  // Reset the timer

        // If a callback function is provided, call it
        if (callback != nullptr) {
          callback();
        }
      }
    }

    // Optional method to manually reset the delay
    void reset() {
      previousMillis = millis();
    }
};
