# The Fat Cat Polygraph Project

Have a cat on a diet? Have a roommate and share the feeding duties?

Does that little fatso tell bold-faced lies about whether he's been fed?

Yeah. Of course he does. That's why I started the Fat Cat Polygraph Project,
a microcontroller that lives under the sink with one simple job: fact check
the cat's statement that he still hasn't been fed.

## Summary

Two buttons. Two LEDs. If an LED is on, the cat is telling the truth (guess
that's why he woke me up). Get the cat food and press the matching button.
Several hours later, the other LED will come on. Dinnertime for fatso!

When it's not feeding time, the LEDs will briefly blink once a minute - just
to make sure everything's working.

First time it turns on, both LEDs will blink a few times and stay lit. Press the
button for the next meal and the thing is good-to-go. Screw it up? Press both buttons
at the same time and everything will reset.

## The Hardware

You probably have this stuff lying around from other projects. You need:

- An arduino compatible microcontroller (I used a Teensy 2.0)
- 2 buttons (I used 2 Cherry MX switches I had lying around)
- 2 LEDs (I used some 3mm red ones, because they fit in the MX switches)
- The right resistors for your LEDs. But you knew that already, right?

## The Software

The pins used for the buttons and LEDs are at the top of the file. Change
those suckers. Or use the same ones I did - hey, I know they work.

I feed my cat before work, around 0830, and after I get home, around 1730.
That's how I picked how long it waits before it starts advertising the next
meal. Change these values to suit the preference of your own rotund balls of
fur. If DEBUG is defined it'll suggest feeding him every 10 seconds - the
catball might enjoy this but I can't recommend it once you've figured about
which pins should be connected to which buttons.

## Things I'd Do If I Cared

This handles what I want it to do. If you wanted to, you could

- Make it handle 3 meals (gasp!)
- Make it use only one button. Really only needs one, and reset could be press
  and hold. But I had two switches in a box. So I didn't. You can!