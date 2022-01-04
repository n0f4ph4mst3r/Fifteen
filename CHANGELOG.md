#### v2.1.0 (2022-01-04)

##### Documentation Changes

* **README.md:**  fix badges [4bfa184a](https://github.com/n0f4ph4mst3r/Fifteen/commit/4bfa184a)

### v2.1.0 (2022-01-04)

##### Chores

* **CMakeLists.txt:**
  *  add override ${CMAKE_CONFIGURATION_TYPES}, if ${CMAKE_BUILD_TYPE} defined [10f3f637](https://github.com/n0f4ph4mst3r/Fifteen/commit/10f3f637)
  *  remove bincrafters remote [806452d4](https://github.com/n0f4ph4mst3r/Fifteen/commit/806452d4)
  *  add install instructions [3f91c07d](https://github.com/n0f4ph4mst3r/Fifteen/commit/3f91c07d)

##### Documentation Changes

* **BUILDING.md:**  update build-insctructions [1422bc82](https://github.com/n0f4ph4mst3r/Fifteen/commit/1422bc82)
* **License.md:**  update copyrating [693de02d](https://github.com/n0f4ph4mst3r/Fifteen/commit/693de02d)
* **.gitignore:**  add bin directory [ea771db6](https://github.com/n0f4ph4mst3r/Fifteen/commit/ea771db6)

##### New Features

*  add CI support [105c9eac](https://github.com/n0f4ph4mst3r/Fifteen/commit/105c9eac)

##### Refactors

* **Puzzle:**  small changes in default constructor [39bd1581](https://github.com/n0f4ph4mst3r/Fifteen/commit/39bd1581)

## v2.0.0 (2021-12-30)

##### Chores

* **CMakeLists.txt:**  add bincrafters remote URL ([f5a2206d](https://github.com/n0f4ph4mst3r/Fifteen/commit/f5a2206d))

##### Documentation Changes

*  add license file (b15dabc2)
* **BUILDING.md:**  update build-insctructions ([bda4f23a](https://github.com/n0f4ph4mst3r/Fifteen/commit/bda4f23a))

##### Bug Fixes

*  disable resize window for Mac an Linux ([67546822](https://github.com/n0f4ph4mst3r/Fifteen/commit/67546822))

##### Other Changes

* **CMakeLists.txt:**  fix command for tests ([7d38a709](https://github.com/n0f4ph4mst3r/Fifteen/commit/7d38a709))
*  delete .travis.yml ([acebdcec](https://github.com/n0f4ph4mst3r/Fifteen/commit/acebdcec))

##### Refactors

* **CMakeLists.txt:**  remove conan_cmake_run() macros ([d82b2b34](https://github.com/n0f4ph4mst3r/Fifteen/commit/d82b2b34))

### v2.0.0-beta-0.1.0 (2021-12-25)

##### Documentation Changes

* **.travis.yml:**  add .travis.yml ([227ae63d](https://github.com/n0f4ph4mst3r/Fifteen/commit/227ae63d))
* **BUILDING.md:**  update BUILDING.md ([b415dfc7](https://github.com/n0f4ph4mst3r/Fifteen/commit/b415dfc7))

#### v2.0.0-beta-0.0.1 (2021-12-24)

##### Chores

* **CMakeLists.txt:**  add conan-instalation options ([8d97f977](https://github.com/n0f4ph4mst3r/Fifteen/commit/8d97f977))

##### Documentation Changes

* **BUILDING.md:**  update BUILDING.md ([b3a96225](https://github.com/n0f4ph4mst3r/Fifteen/commit/b3a96225))

### v2.0.0-beta (2021-12-22)

##### Chores

* **CMakeLists.txt:**  change the installation method dependencies ([5a547a74](https://github.com/n0f4ph4mst3r/Fifteen/commit/5a547a74))

##### Documentation Changes

* **.gitignore:**  add new directories: 'debug/' and 'release/' ([9d5873d5](https://github.com/n0f4ph4mst3r/Fifteen/commit/[9d5873d5]))
*  add BUILDING.md ([3e760df4](https://github.com/n0f4ph4mst3r/Fifteen/commit/[3e760df4]))
*  add README.md ([d3d7b202](https://github.com/n0f4ph4mst3r/Fifteen/commit/[d3d7b202]))

##### Other Changes

*  rename 'lib' directory to 'modules' ([dca300c9](https://github.com/n0f4ph4mst3r/Fifteen/commit/[dca300c9]))
*  rename workspace.png to BACKGROUND.png ([7cffa2b6](https://github.com/n0f4ph4mst3r/Fifteen/commit/[7cffa2b6]))
* **.gitattributes:**  update .gitattributes ([f09c4525](https://github.com/n0f4ph4mst3r/Fifteen/commit/[f09c4525]))

##### Performance Improvements

*  optimized animation work due to the use of smart pointers ([296c9df9](https://github.com/n0f4ph4mst3r/Fifteen/commit/296c9df9])


### v2.0.0-alpha-0.2.0 (2021-12-13)

##### Chores

* **CMakeLists.txt:**  add PNG-resource for MacOS ([9e69b7d0](https://github.com/n0f4ph4mst3r/Fifteen/commit/9e69b7d0))
*  reorganize the project structure ([45e6557c](https://github.com/n0f4ph4mst3r/Fifteen/commit/45e6557c))

##### Bug Fixes

* **PuzzleApp.cpp:**  fix preprocessor directives ([f65f014b](https://github.com/n0f4ph4mst3r/Fifteen/commit/f65f014b))

### v2.0.0-alpha-0.1.0 (2021-12-12)

##### Bug Fixes

*  correct wxFrame size ([9c28faf9](https://github.com/n0f4ph4mst3r/Fifteen/commit/9c28faf9))
* **image_resources.rc:**  rename icon file (from aaaaaaaaa to aaaaaaaa_logo) ([28717e3b](https://github.com/n0f4ph4mst3r/Fifteen/commit/28717e3b))

##### Other Changes

* **PuzzleTests:**  remove Llabel-argument from asserts ([14d1b2f0](https://github.com/n0f4ph4mst3r/Fifteen/commit/14d1b2f0))
*  edit CMakeLists.txt ([35cb9b6d](https://github.com/n0f4ph4mst3r/Fifteen/commit/35cb9b6d))
*  add aaaaaaa_logo.XPM ([3a69fae9](https://github.com/n0f4ph4mst3r/Fifteen/commit/3a69fae9))
* **BACKGROUND.png:**  add converted header ([88ab323e](https://github.com/n0f4ph4mst3r/Fifteen/commit/88ab323e))

##### Refactors

* **PuzzleApp.cpp:**  include aaaaaaa_logo.XPM and BACKGROUND.h ([41a59939](https://github.com/n0f4ph4mst3r/Fifteen/commit/41a59939))

### v2.0.0-alpha (2021-12-12)

##### Chores

*  rename app_icon to image_resources ([c3729e51](https://github.com/n0f4ph4mst3r/Fifteen/commit/c3729e51))
*  repurpose Visual Studio Project to CMake ([5bf704ec](https://github.com/n0f4ph4mst3r/Fifteen/commit/5bf704ec))

##### Other Changes

*  edit CMakeLists files ([bead9392](https://github.com/n0f4ph4mst3r/Fifteen/commit/bead9392))
*  change directory of tests ([a73ee237](https://github.com/n0f4ph4mst3r/Fifteen/commit/a73ee237))
* **app_icon:**  add new resource(BACKGROUND) ([caee7b06](https://github.com/n0f4ph4mst3r/Fifteen/commit/caee7b06))

##### Refactors

* **wxImagePanel:**  change constructor parameters ([4ab9f8ec](https://github.com/n0f4ph4mst3r/Fifteen/commit/4ab9f8ec))
* **Puzzle:**  change constructor parameters ([03753723](https://github.com/n0f4ph4mst3r/Fifteen/commit/03753723))

### v1.2.0 (2021-11-22)

##### Chores

* **LINK:**  add / change paths of additional library directories for x64 configuration ([6a731d95](https://github.com/n0f4ph4mst3r/Fifteen/commit/6a731d95))
*  rename class FifteenApp to PuzzleApp ([e29a34be](https://github.com/n0f4ph4mst3r/Fifteen/commit/e29a34be))
*  rename class Fiffteen to Puzzle ([3bbaf86d](https://github.com/n0f4ph4mst3r/Fifteen/commit/3bbaf86d))
*  rename Fifteen.h to Puzzle.h ([8e207bf9](https://github.com/n0f4ph4mst3r/Fifteen/commit/8e207bf9))
*  delete unused files ([728f84e1](https://github.com/n0f4ph4mst3r/Fifteen/commit/728f84e1))
*  bump language standard (from 14 to 20) ([c0ba6f6e](https://github.com/n0f4ph4mst3r/Fifteen/commit/c0ba6f6e))
* **.gitignore:**  update ([a59d36da](https://github.com/n0f4ph4mst3r/Fifteen/commit/a59d36da))

##### Refactors

* **Puzzle:**
  *  add default constructor ([88b419e5](https://github.com/n0f4ph4mst3r/Fifteen/commit/88b419e5))
  *  remove wxBitmap bmp ([49403028](https://github.com/n0f4ph4mst3r/Fifteen/commit/49403028))
*  rename class FifteenApp to PuzzleApp ([46f3437](https://github.com/n0f4ph4mst3r/Fifteen/commit/46f3437))
* **wxImagePanel:**  change the access specifier for event handlers (from public to private) ([5142763b](https://github.com/n0f4ph4mst3r/Fifteen/commit/5142763b))
* **Fifteen:**  transfer the logic of creation of a puzlle ([55746660](https://github.com/n0f4ph4mst3r/Fifteen/commit/55746660))
* **image-panel:**  add movement logic for block in render-timer method ([d51c3109](https://github.com/n0f4ph4mst3r/Fifteen/commit/d51c3109))

##### Code Style Changes

*  edit comments ([5070e32b](https://github.com/n0f4ph4mst3r/Fifteen/commit/5070e32b))
*  small changes ([3508c761](https://github.com/n0f4ph4mst3r/Fifteen/commit/3508c761))
*  small changes ([0fc4affd](https://github.com/n0f4ph4mst3r/Fifteen/commit/0fc4affd))

##### Tests

* **Puzzle:**  create simple tests ([0106c7a3](https://github.com/n0f4ph4mst3r/Fifteen/commit/0106c7a3))

### v1.1.0 (2021-11-03)

##### Other Changes

* **main-window:**
  *  change icon ([2e7183d8](https://github.com/n0f4ph4mst3r/Fifteen/commit/2e7183d8))
  *  change window style ([bbea1483](https://github.com/n0f4ph4mst3r/Fifteen/commit/bbea1483))
  *  change header ([f11b0675](https://github.com/n0f4ph4mst3r/Fifteen/commit/f11b0675))

##### Code Style Changes

*  add comments ([53dc2cdc](https://github.com/n0f4ph4mst3r/Fifteen/commit/53dc2cdc))

## v1.0.0 (2021-11-02)

##### Other Changes

* **image-panel:**  change render-algorithm ([41874aef](https://github.com/n0f4ph4mst3r/Fifteen/commit/41874aefbab157c07b8bbc7e65a535b1016e04fa))

### v1.0.0-alpha (2021-11-02)

##### New Features

* **image-panel:**  add animation for blocks ([80e34cd8](https://github.com/n0f4ph4mst3r/Fifteen/commit/80e34cd82485f0a438b650ecb03010a7e49e294a))

### v0.3.0 (2021-11-02)

##### Chores

*  delete unused files ([b722ee4b](https://github.com/n0f4ph4mst3r/Fifteen/commit/b722ee4b043776f27dba683869e09bbaee6f3cc5))

##### New Features

* **image-panel:**  blocks using render-timer now ([52ddecfc](https://github.com/n0f4ph4mst3r/Fifteen/commit/52ddecfcbc30f88e2cf5407353a77c185cfeeca3))

### v0.2.0 (2021-11-02)

##### New Features

* **image-panel:**  the blocks are move now ([12e7f21d](https://github.com/n0f4ph4mst3r/Fifteen/commit/12e7f21d1f21855898311c31ded0ca17c49cbe18))

### v0.1.0 (2021-11-02)

##### Other Changes

*  add PNG for workspace ([4e17ce21](https://github.com/n0f4ph4mst3r/Fifteen/commit/4e17ce21be55fac1d9546e1a15725cd3c4b18f1f))

