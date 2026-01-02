This Github repository hosts a record of the hardware and software for my German midterm project, which is written about here: [sethmueller.page](sethmueller.page). I didn't use version control when developing everything so this merely serves as a place to share the code.

**KiCad Files**: All of the PCB design is in the `germanymapKiCadArchive.zip` file. It should work in KiCad 9.0. I developed this across multiple computers so the footprints may be a bit messed up, if you don't refill the zones it should be fine.

**Software for the ESP32**: All software loaded on the ESP32 and configuration needed to do so with PlatformIO can be found in the `PlatformIOCode` folder. The two main files of importance are in the `PlatformIOCode/src` folder.

**Webapp for categorization**: The HTML, CSS, and JS files can be found in the `WebApp` folder. Unfortunately none of the background images will load anymore as the Canva links I was using to host them have expired, but the rest of the app is still funcitonal. You can also run it online [here](https://germanyapatagorizer.oneapp.dev/).
