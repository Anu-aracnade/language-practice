# In this code we are testing an external module (pyttx3) which help 
# us to generate speech form the text.

import pyttsx3
engine = pyttsx3.init()

# For Mac, If you face error related to "pyobjc" when running the `init()` method :
# Install 9.0.1 version of pyobjc : "pip install pyobjc>=9.0.1"

engine.say("Hey what's up, getting started you know !")
engine.runAndWait()