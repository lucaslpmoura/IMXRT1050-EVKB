INCLUDE(CMakeForceCompiler)

# CROSS COMPILER SETTING
SET(CMAKE_SYSTEM_NAME Generic)
CMAKE_MINIMUM_REQUIRED (VERSION 2.6)

# THE VERSION NUMBER
SET (Tutorial_VERSION_MAJOR 1)
SET (Tutorial_VERSION_MINOR 0)

# ENABLE ASM
ENABLE_LANGUAGE(ASM)

SET(CMAKE_STATIC_LIBRARY_PREFIX)
SET(CMAKE_STATIC_LIBRARY_SUFFIX)

SET(CMAKE_EXECUTABLE_LIBRARY_PREFIX)
SET(CMAKE_EXECUTABLE_LIBRARY_SUFFIX)

 
# CURRENT DIRECTORY
SET(ProjDirPath ${CMAKE_CURRENT_SOURCE_DIR})


SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -DDEBUG")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -D__STARTUP_CLEAR_BSS")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -D__STARTUP_INITIALIZE_NONCACHEDATA")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -g")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -Wall")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -fno-common")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -ffunction-sections")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -fdata-sections")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -ffreestanding")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -fno-builtin")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -mthumb")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -mapcs")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -std=gnu99")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -mcpu=cortex-m7")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -mfloat-abi=hard")

SET(CMAKE_ASM_FLAGS_DEBUG "${CMAKE_ASM_FLAGS_DEBUG} -mfpu=fpv5-d16")

SET(CMAKE_ASM_FLAGS_SDRAM_DEBUG "${CMAKE_ASM_FLAGS_SDRAM_DEBUG} -D__STARTUP_CLEAR_BSS")

SET(CMAKE_ASM_FLAGS_SDRAM_DEBUG "${CMAKE_ASM_FLAGS_SDRAM_DEBUG} -D__STARTUP_INITIALIZE_NONCACHEDATA")

SET(CMAKE_ASM_FLAGS_SDRAM_DEBUG "${CMAKE_ASM_FLAGS_SDRAM_DEBUG} -g")

SET(CMAKE_ASM_FLAGS_SDRAM_DEBUG "${CMAKE_ASM_FLAGS_SDRAM_DEBUG} -Wall")

SET(CMAKE_ASM_FLAGS_SDRAM_DEBUG "${CMAKE_ASM_FLAGS_SDRAM_DEBUG} -fno-common")

SET(CMAKE_ASM_FLAGS_SDRAM_DEBUG "${CMAKE_ASM_FLAGS_SDRAM_DEBUG} -ffunction-sections")

SET(CMAKE_ASM_FLAGS_SDRAM_DEBUG "${CMAKE_ASM_FLAGS_SDRAM_DEBUG} -fdata-sections")

SET(CMAKE_ASM_FLAGS_SDRAM_DEBUG "${CMAKE_ASM_FLAGS_SDRAM_DEBUG} -ffreestanding")

SET(CMAKE_ASM_FLAGS_SDRAM_DEBUG "${CMAKE_ASM_FLAGS_SDRAM_DEBUG} -fno-builtin")

SET(CMAKE_ASM_FLAGS_SDRAM_DEBUG "${CMAKE_ASM_FLAGS_SDRAM_DEBUG} -mthumb")

SET(CMAKE_ASM_FLAGS_SDRAM_DEBUG "${CMAKE_ASM_FLAGS_SDRAM_DEBUG} -mapcs")

SET(CMAKE_ASM_FLAGS_SDRAM_DEBUG "${CMAKE_ASM_FLAGS_SDRAM_DEBUG} -std=gnu99")

SET(CMAKE_ASM_FLAGS_SDRAM_DEBUG "${CMAKE_ASM_FLAGS_SDRAM_DEBUG} -mcpu=cortex-m7")

SET(CMAKE_ASM_FLAGS_SDRAM_DEBUG "${CMAKE_ASM_FLAGS_SDRAM_DEBUG} -mfloat-abi=hard")

SET(CMAKE_ASM_FLAGS_SDRAM_DEBUG "${CMAKE_ASM_FLAGS_SDRAM_DEBUG} -mfpu=fpv5-d16")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -D__STARTUP_CLEAR_BSS")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -D__STARTUP_INITIALIZE_NONCACHEDATA")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -Wall")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -fno-common")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -ffunction-sections")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -fdata-sections")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -ffreestanding")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -fno-builtin")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -mthumb")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -mapcs")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -std=gnu99")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -mcpu=cortex-m7")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -mfloat-abi=hard")

SET(CMAKE_ASM_FLAGS_RELEASE "${CMAKE_ASM_FLAGS_RELEASE} -mfpu=fpv5-d16")

SET(CMAKE_ASM_FLAGS_SDRAM_RELEASE "${CMAKE_ASM_FLAGS_SDRAM_RELEASE} -D__STARTUP_CLEAR_BSS")

SET(CMAKE_ASM_FLAGS_SDRAM_RELEASE "${CMAKE_ASM_FLAGS_SDRAM_RELEASE} -D__STARTUP_INITIALIZE_NONCACHEDATA")

SET(CMAKE_ASM_FLAGS_SDRAM_RELEASE "${CMAKE_ASM_FLAGS_SDRAM_RELEASE} -Wall")

SET(CMAKE_ASM_FLAGS_SDRAM_RELEASE "${CMAKE_ASM_FLAGS_SDRAM_RELEASE} -fno-common")

SET(CMAKE_ASM_FLAGS_SDRAM_RELEASE "${CMAKE_ASM_FLAGS_SDRAM_RELEASE} -ffunction-sections")

SET(CMAKE_ASM_FLAGS_SDRAM_RELEASE "${CMAKE_ASM_FLAGS_SDRAM_RELEASE} -fdata-sections")

SET(CMAKE_ASM_FLAGS_SDRAM_RELEASE "${CMAKE_ASM_FLAGS_SDRAM_RELEASE} -ffreestanding")

SET(CMAKE_ASM_FLAGS_SDRAM_RELEASE "${CMAKE_ASM_FLAGS_SDRAM_RELEASE} -fno-builtin")

SET(CMAKE_ASM_FLAGS_SDRAM_RELEASE "${CMAKE_ASM_FLAGS_SDRAM_RELEASE} -mthumb")

SET(CMAKE_ASM_FLAGS_SDRAM_RELEASE "${CMAKE_ASM_FLAGS_SDRAM_RELEASE} -mapcs")

SET(CMAKE_ASM_FLAGS_SDRAM_RELEASE "${CMAKE_ASM_FLAGS_SDRAM_RELEASE} -std=gnu99")

SET(CMAKE_ASM_FLAGS_SDRAM_RELEASE "${CMAKE_ASM_FLAGS_SDRAM_RELEASE} -mcpu=cortex-m7")

SET(CMAKE_ASM_FLAGS_SDRAM_RELEASE "${CMAKE_ASM_FLAGS_SDRAM_RELEASE} -mfloat-abi=hard")

SET(CMAKE_ASM_FLAGS_SDRAM_RELEASE "${CMAKE_ASM_FLAGS_SDRAM_RELEASE} -mfpu=fpv5-d16")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DDEBUG")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DCPU_MIMXRT1052DVL6A")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DFSL_RTOS_FREE_RTOS")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DA_LITTLE_ENDIAN")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -mcpu=cortex-m7")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -mfloat-abi=hard")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -mfpu=fpv5-d16")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -mthumb")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -MMD")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -MP")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fno-common")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -ffunction-sections")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fdata-sections")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -ffreestanding")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fno-builtin")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -mapcs")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -std=gnu99")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g")

SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O1")

SET(CMAKE_C_FLAGS_SDRAM_DEBUG "${CMAKE_C_FLAGS_SDRAM_DEBUG} -DSDRAM_MPU_INIT")

SET(CMAKE_C_FLAGS_SDRAM_DEBUG "${CMAKE_C_FLAGS_SDRAM_DEBUG} -DCPU_MIMXRT1052DVL6A")

SET(CMAKE_C_FLAGS_SDRAM_DEBUG "${CMAKE_C_FLAGS_SDRAM_DEBUG} -DFSL_RTOS_FREE_RTOS")

SET(CMAKE_C_FLAGS_SDRAM_DEBUG "${CMAKE_C_FLAGS_SDRAM_DEBUG} -DA_LITTLE_ENDIAN")

SET(CMAKE_C_FLAGS_SDRAM_DEBUG "${CMAKE_C_FLAGS_SDRAM_DEBUG} -mcpu=cortex-m7")

SET(CMAKE_C_FLAGS_SDRAM_DEBUG "${CMAKE_C_FLAGS_SDRAM_DEBUG} -Wall")

SET(CMAKE_C_FLAGS_SDRAM_DEBUG "${CMAKE_C_FLAGS_SDRAM_DEBUG} -mfloat-abi=hard")

SET(CMAKE_C_FLAGS_SDRAM_DEBUG "${CMAKE_C_FLAGS_SDRAM_DEBUG} -mfpu=fpv5-d16")

SET(CMAKE_C_FLAGS_SDRAM_DEBUG "${CMAKE_C_FLAGS_SDRAM_DEBUG} -mthumb")

SET(CMAKE_C_FLAGS_SDRAM_DEBUG "${CMAKE_C_FLAGS_SDRAM_DEBUG} -MMD")

SET(CMAKE_C_FLAGS_SDRAM_DEBUG "${CMAKE_C_FLAGS_SDRAM_DEBUG} -MP")

SET(CMAKE_C_FLAGS_SDRAM_DEBUG "${CMAKE_C_FLAGS_SDRAM_DEBUG} -fno-common")

SET(CMAKE_C_FLAGS_SDRAM_DEBUG "${CMAKE_C_FLAGS_SDRAM_DEBUG} -ffunction-sections")

SET(CMAKE_C_FLAGS_SDRAM_DEBUG "${CMAKE_C_FLAGS_SDRAM_DEBUG} -fdata-sections")

SET(CMAKE_C_FLAGS_SDRAM_DEBUG "${CMAKE_C_FLAGS_SDRAM_DEBUG} -ffreestanding")

SET(CMAKE_C_FLAGS_SDRAM_DEBUG "${CMAKE_C_FLAGS_SDRAM_DEBUG} -fno-builtin")

SET(CMAKE_C_FLAGS_SDRAM_DEBUG "${CMAKE_C_FLAGS_SDRAM_DEBUG} -mapcs")

SET(CMAKE_C_FLAGS_SDRAM_DEBUG "${CMAKE_C_FLAGS_SDRAM_DEBUG} -std=gnu99")

SET(CMAKE_C_FLAGS_SDRAM_DEBUG "${CMAKE_C_FLAGS_SDRAM_DEBUG} -g")

SET(CMAKE_C_FLAGS_SDRAM_DEBUG "${CMAKE_C_FLAGS_SDRAM_DEBUG} -O1")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -DNDEBUG")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -DCPU_MIMXRT1052DVL6A")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -DFSL_RTOS_FREE_RTOS")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -DA_LITTLE_ENDIAN")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Os")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -Wall")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -fno-common")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -ffunction-sections")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -fdata-sections")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -ffreestanding")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -fno-builtin")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -mthumb")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -mapcs")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -std=gnu99")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -mcpu=cortex-m7")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -mfloat-abi=hard")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -mfpu=fpv5-d16")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -MMD")

SET(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -MP")

SET(CMAKE_C_FLAGS_SDRAM_RELEASE "${CMAKE_C_FLAGS_SDRAM_RELEASE} -DSDRAM_MPU_INIT")

SET(CMAKE_C_FLAGS_SDRAM_RELEASE "${CMAKE_C_FLAGS_SDRAM_RELEASE} -DCPU_MIMXRT1052DVL6A")

SET(CMAKE_C_FLAGS_SDRAM_RELEASE "${CMAKE_C_FLAGS_SDRAM_RELEASE} -DFSL_RTOS_FREE_RTOS")

SET(CMAKE_C_FLAGS_SDRAM_RELEASE "${CMAKE_C_FLAGS_SDRAM_RELEASE} -DA_LITTLE_ENDIAN")

SET(CMAKE_C_FLAGS_SDRAM_RELEASE "${CMAKE_C_FLAGS_SDRAM_RELEASE} -Os")

SET(CMAKE_C_FLAGS_SDRAM_RELEASE "${CMAKE_C_FLAGS_SDRAM_RELEASE} -Wall")

SET(CMAKE_C_FLAGS_SDRAM_RELEASE "${CMAKE_C_FLAGS_SDRAM_RELEASE} -fno-common")

SET(CMAKE_C_FLAGS_SDRAM_RELEASE "${CMAKE_C_FLAGS_SDRAM_RELEASE} -ffunction-sections")

SET(CMAKE_C_FLAGS_SDRAM_RELEASE "${CMAKE_C_FLAGS_SDRAM_RELEASE} -fdata-sections")

SET(CMAKE_C_FLAGS_SDRAM_RELEASE "${CMAKE_C_FLAGS_SDRAM_RELEASE} -ffreestanding")

SET(CMAKE_C_FLAGS_SDRAM_RELEASE "${CMAKE_C_FLAGS_SDRAM_RELEASE} -fno-builtin")

SET(CMAKE_C_FLAGS_SDRAM_RELEASE "${CMAKE_C_FLAGS_SDRAM_RELEASE} -mthumb")

SET(CMAKE_C_FLAGS_SDRAM_RELEASE "${CMAKE_C_FLAGS_SDRAM_RELEASE} -mapcs")

SET(CMAKE_C_FLAGS_SDRAM_RELEASE "${CMAKE_C_FLAGS_SDRAM_RELEASE} -std=gnu99")

SET(CMAKE_C_FLAGS_SDRAM_RELEASE "${CMAKE_C_FLAGS_SDRAM_RELEASE} -mcpu=cortex-m7")

SET(CMAKE_C_FLAGS_SDRAM_RELEASE "${CMAKE_C_FLAGS_SDRAM_RELEASE} -mfloat-abi=hard")

SET(CMAKE_C_FLAGS_SDRAM_RELEASE "${CMAKE_C_FLAGS_SDRAM_RELEASE} -mfpu=fpv5-d16")

SET(CMAKE_C_FLAGS_SDRAM_RELEASE "${CMAKE_C_FLAGS_SDRAM_RELEASE} -MMD")

SET(CMAKE_C_FLAGS_SDRAM_RELEASE "${CMAKE_C_FLAGS_SDRAM_RELEASE} -MP")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -mcpu=cortex-m7")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -mfloat-abi=hard")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -mfpu=fpv5-d16")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -mthumb")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -MMD")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -MP")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-common")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -ffunction-sections")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fdata-sections")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -ffreestanding")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-builtin")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -mapcs")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-rtti")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-exceptions")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O1")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Os")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -fno-common")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -ffunction-sections")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -fdata-sections")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -ffreestanding")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -fno-builtin")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -mthumb")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -mapcs")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -fno-rtti")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -fno-exceptions")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -mcpu=cortex-m7")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -mfloat-abi=hard")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -mfpu=fpv5-d16")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -MMD")

SET(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -MP")

SET(CMAKE_CXX_FLAGS_SDRAM_DEBUG "${CMAKE_CXX_FLAGS_SDRAM_DEBUG} -mcpu=cortex-m7")

SET(CMAKE_CXX_FLAGS_SDRAM_DEBUG "${CMAKE_CXX_FLAGS_SDRAM_DEBUG} -Wall")

SET(CMAKE_CXX_FLAGS_SDRAM_DEBUG "${CMAKE_CXX_FLAGS_SDRAM_DEBUG} -mfloat-abi=hard")

SET(CMAKE_CXX_FLAGS_SDRAM_DEBUG "${CMAKE_CXX_FLAGS_SDRAM_DEBUG} -mfpu=fpv5-d16")

SET(CMAKE_CXX_FLAGS_SDRAM_DEBUG "${CMAKE_CXX_FLAGS_SDRAM_DEBUG} -mthumb")

SET(CMAKE_CXX_FLAGS_SDRAM_DEBUG "${CMAKE_CXX_FLAGS_SDRAM_DEBUG} -MMD")

SET(CMAKE_CXX_FLAGS_SDRAM_DEBUG "${CMAKE_CXX_FLAGS_SDRAM_DEBUG} -MP")

SET(CMAKE_CXX_FLAGS_SDRAM_DEBUG "${CMAKE_CXX_FLAGS_SDRAM_DEBUG} -fno-common")

SET(CMAKE_CXX_FLAGS_SDRAM_DEBUG "${CMAKE_CXX_FLAGS_SDRAM_DEBUG} -ffunction-sections")

SET(CMAKE_CXX_FLAGS_SDRAM_DEBUG "${CMAKE_CXX_FLAGS_SDRAM_DEBUG} -fdata-sections")

SET(CMAKE_CXX_FLAGS_SDRAM_DEBUG "${CMAKE_CXX_FLAGS_SDRAM_DEBUG} -ffreestanding")

SET(CMAKE_CXX_FLAGS_SDRAM_DEBUG "${CMAKE_CXX_FLAGS_SDRAM_DEBUG} -fno-builtin")

SET(CMAKE_CXX_FLAGS_SDRAM_DEBUG "${CMAKE_CXX_FLAGS_SDRAM_DEBUG} -mapcs")

SET(CMAKE_CXX_FLAGS_SDRAM_DEBUG "${CMAKE_CXX_FLAGS_SDRAM_DEBUG} -fno-rtti")

SET(CMAKE_CXX_FLAGS_SDRAM_DEBUG "${CMAKE_CXX_FLAGS_SDRAM_DEBUG} -fno-exceptions")

SET(CMAKE_CXX_FLAGS_SDRAM_DEBUG "${CMAKE_CXX_FLAGS_SDRAM_DEBUG} -g")

SET(CMAKE_CXX_FLAGS_SDRAM_DEBUG "${CMAKE_CXX_FLAGS_SDRAM_DEBUG} -O1")

SET(CMAKE_CXX_FLAGS_SDRAM_RELEASE "${CMAKE_CXX_FLAGS_SDRAM_RELEASE} -Os")

SET(CMAKE_CXX_FLAGS_SDRAM_RELEASE "${CMAKE_CXX_FLAGS_SDRAM_RELEASE} -Wall")

SET(CMAKE_CXX_FLAGS_SDRAM_RELEASE "${CMAKE_CXX_FLAGS_SDRAM_RELEASE} -fno-common")

SET(CMAKE_CXX_FLAGS_SDRAM_RELEASE "${CMAKE_CXX_FLAGS_SDRAM_RELEASE} -ffunction-sections")

SET(CMAKE_CXX_FLAGS_SDRAM_RELEASE "${CMAKE_CXX_FLAGS_SDRAM_RELEASE} -fdata-sections")

SET(CMAKE_CXX_FLAGS_SDRAM_RELEASE "${CMAKE_CXX_FLAGS_SDRAM_RELEASE} -ffreestanding")

SET(CMAKE_CXX_FLAGS_SDRAM_RELEASE "${CMAKE_CXX_FLAGS_SDRAM_RELEASE} -fno-builtin")

SET(CMAKE_CXX_FLAGS_SDRAM_RELEASE "${CMAKE_CXX_FLAGS_SDRAM_RELEASE} -mthumb")

SET(CMAKE_CXX_FLAGS_SDRAM_RELEASE "${CMAKE_CXX_FLAGS_SDRAM_RELEASE} -mapcs")

SET(CMAKE_CXX_FLAGS_SDRAM_RELEASE "${CMAKE_CXX_FLAGS_SDRAM_RELEASE} -fno-rtti")

SET(CMAKE_CXX_FLAGS_SDRAM_RELEASE "${CMAKE_CXX_FLAGS_SDRAM_RELEASE} -fno-exceptions")

SET(CMAKE_CXX_FLAGS_SDRAM_RELEASE "${CMAKE_CXX_FLAGS_SDRAM_RELEASE} -mcpu=cortex-m7")

SET(CMAKE_CXX_FLAGS_SDRAM_RELEASE "${CMAKE_CXX_FLAGS_SDRAM_RELEASE} -mfloat-abi=hard")

SET(CMAKE_CXX_FLAGS_SDRAM_RELEASE "${CMAKE_CXX_FLAGS_SDRAM_RELEASE} -mfpu=fpv5-d16")

SET(CMAKE_CXX_FLAGS_SDRAM_RELEASE "${CMAKE_CXX_FLAGS_SDRAM_RELEASE} -MMD")

SET(CMAKE_CXX_FLAGS_SDRAM_RELEASE "${CMAKE_CXX_FLAGS_SDRAM_RELEASE} -MP")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -g")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} --specs=nano.specs")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} --specs=nosys.specs")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -Wall")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -fno-common")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -ffunction-sections")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -fdata-sections")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -ffreestanding")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -fno-builtin")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -mthumb")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -mapcs")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} --gc-sections")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -static")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -z")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} muldefs")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -mcpu=cortex-m7")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -mfloat-abi=hard")

SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -mfpu=fpv5-d16")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} --specs=nano.specs")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} --specs=nosys.specs")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -Wall")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -fno-common")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -ffunction-sections")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -fdata-sections")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -ffreestanding")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -fno-builtin")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -mthumb")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -mapcs")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} --gc-sections")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -static")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -z")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} muldefs")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -mcpu=cortex-m7")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -mfloat-abi=hard")

SET(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -mfpu=fpv5-d16")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG} -g")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG} --specs=nano.specs")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG} --specs=nosys.specs")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG} -Wall")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG} -fno-common")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG} -ffunction-sections")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG} -fdata-sections")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG} -ffreestanding")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG} -fno-builtin")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG} -mthumb")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG} -mapcs")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG} --gc-sections")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG} -static")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG} -z")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG} muldefs")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG} -mcpu=cortex-m7")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG} -mfloat-abi=hard")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG} -mfpu=fpv5-d16")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE} --specs=nano.specs")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE} --specs=nosys.specs")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE} -Wall")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE} -fno-common")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE} -ffunction-sections")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE} -fdata-sections")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE} -ffreestanding")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE} -fno-builtin")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE} -mthumb")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE} -mapcs")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE} --gc-sections")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE} -static")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE} -z")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE} -Xlinker")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE} muldefs")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE} -mcpu=cortex-m7")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE} -mfloat-abi=hard")

SET(CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE} -mfpu=fpv5-d16")

include_directories(${ProjDirPath}/../../../..)

include_directories(${ProjDirPath}/..)

include_directories(${ProjDirPath}/../../../../../../rtos/freertos/Source/portable/GCC/ARM_CM4F)

include_directories(${ProjDirPath}/../../../../../../CMSIS/Include)

include_directories(${ProjDirPath}/../../../../../../devices)

include_directories(${ProjDirPath}/../../../../../../rtos/freertos/Source/include)

include_directories(${ProjDirPath}/../../../../../../middleware/wifi_qca/port/boards/evkmimxrt1050/freertos/gt202)

include_directories(${ProjDirPath}/../../../../../../middleware/wifi_qca/port/boards/evkmimxrt1050/freertos)

include_directories(${ProjDirPath}/../../../../../../middleware/wifi_qca/port/env/freertos)

include_directories(${ProjDirPath}/../../../../../../middleware/wifi_qca)

include_directories(${ProjDirPath}/../../../../../../middleware/wifi_qca/include)

include_directories(${ProjDirPath}/../../../../../../middleware/wifi_qca/include/AR6002)

include_directories(${ProjDirPath}/../../../../../../middleware/wifi_qca/include/AR6002/hw2.0/hw)

include_directories(${ProjDirPath}/../../../../../../middleware/wifi_qca/include/AR6002/hw4.0/hw)

include_directories(${ProjDirPath}/../../../../../../middleware/wifi_qca/custom_src/stack_custom)

include_directories(${ProjDirPath}/../../../../../../middleware/wifi_qca/custom_src/include)

include_directories(${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/include)

include_directories(${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/stack_common)

include_directories(${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/hcd)

include_directories(${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/wmi)

include_directories(${ProjDirPath}/../../../../../../middleware/wifi_qca/port)

include_directories(${ProjDirPath}/../../../../../../middleware/wifi_qca/port/drivers/lpspi_edma_freertos)

include_directories(${ProjDirPath}/../../../../../../devices/MIMXRT1052/drivers)

include_directories(${ProjDirPath}/../../../../../../devices/MIMXRT1052)

include_directories(${ProjDirPath}/../../../../../../devices/MIMXRT1052/utilities/io)

include_directories(${ProjDirPath}/../../../../../../devices/MIMXRT1052/utilities/str)

include_directories(${ProjDirPath}/../../../../../../devices/MIMXRT1052/utilities/log)

include_directories(${ProjDirPath}/../../../../../../devices/MIMXRT1052/utilities)

add_executable(qca_demo.elf 
"${ProjDirPath}/../FreeRTOSConfig.h"
"${ProjDirPath}/../main.c"
"${ProjDirPath}/../wlan_qca400x.c"
"${ProjDirPath}/../wlan_qcom.c"
"${ProjDirPath}/../wlan_qcom.h"
"${ProjDirPath}/../pin_mux.c"
"${ProjDirPath}/../pin_mux.h"
"${ProjDirPath}/../board.c"
"${ProjDirPath}/../board.h"
"${ProjDirPath}/../clock_config.c"
"${ProjDirPath}/../clock_config.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/port/boards/evkmimxrt1050/freertos/gt202/wifi_shield_gt202.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/port/boards/evkmimxrt1050/freertos/wifi_shield.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/port/boards/evkmimxrt1050/freertos/wifi_shield.c"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/port/env/freertos/wifi_port.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/port/env/freertos/wifi_env_port.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/port/env/freertos/wifi_env.c"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/port/env/freertos/wifi_env.h"
"${ProjDirPath}/../../../../../../rtos/freertos/FreeRTOS_for_Kinetis_SDK_v2.0.txt"
"${ProjDirPath}/../../../../../../rtos/freertos/License/license.txt"
"${ProjDirPath}/../../../../../../rtos/freertos/Source/include/croutine.h"
"${ProjDirPath}/../../../../../../rtos/freertos/Source/include/event_groups.h"
"${ProjDirPath}/../../../../../../rtos/freertos/Source/include/FreeRTOS.h"
"${ProjDirPath}/../../../../../../rtos/freertos/Source/include/list.h"
"${ProjDirPath}/../../../../../../rtos/freertos/Source/include/mpu_wrappers.h"
"${ProjDirPath}/../../../../../../rtos/freertos/Source/include/portable.h"
"${ProjDirPath}/../../../../../../rtos/freertos/Source/include/projdefs.h"
"${ProjDirPath}/../../../../../../rtos/freertos/Source/include/queue.h"
"${ProjDirPath}/../../../../../../rtos/freertos/Source/include/semphr.h"
"${ProjDirPath}/../../../../../../rtos/freertos/Source/include/StackMacros.h"
"${ProjDirPath}/../../../../../../rtos/freertos/Source/include/stdint.readme"
"${ProjDirPath}/../../../../../../rtos/freertos/Source/include/task.h"
"${ProjDirPath}/../../../../../../rtos/freertos/Source/include/timers.h"
"${ProjDirPath}/../../../../../../rtos/freertos/Source/include/deprecated_definitions.h"
"${ProjDirPath}/../../../../../../rtos/freertos/Source/include/freertos_tasks_c_additions.h"
"${ProjDirPath}/../../../../../../rtos/freertos/Source/croutine.c"
"${ProjDirPath}/../../../../../../rtos/freertos/Source/list.c"
"${ProjDirPath}/../../../../../../rtos/freertos/Source/queue.c"
"${ProjDirPath}/../../../../../../rtos/freertos/Source/readme.txt"
"${ProjDirPath}/../../../../../../rtos/freertos/Source/tasks.c"
"${ProjDirPath}/../../../../../../rtos/freertos/Source/timers.c"
"${ProjDirPath}/../../../../../../rtos/freertos/Source/event_groups.c"
"${ProjDirPath}/../../../../../../rtos/freertos/Source/portable/readme.txt"
"${ProjDirPath}/../../../../../../rtos/freertos/Source/portable/GCC/ARM_CM4F/fsl_tickless_generic.h"
"${ProjDirPath}/../../../../../../rtos/freertos/Source/portable/GCC/ARM_CM4F/fsl_tickless_systick.c"
"${ProjDirPath}/../../../../../../rtos/freertos/Source/portable/GCC/ARM_CM4F/port.c"
"${ProjDirPath}/../../../../../../rtos/freertos/Source/portable/GCC/ARM_CM4F/portmacro.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/wmi/wmi.c"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/storerecall/dset_api.c"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/stack_common/common_stack_offload.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/stack_common/api_stack_offload.c"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/qapi/qcom_api.c"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/include/dset_api.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/include/driver_cxt.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/include/a_drv_api.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/htc/htc.c"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/hcd/spi_hcd.c"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/driver/driver_main.c"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/api_interface/api_wmi_rx.c"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/api_interface/api_ioctl.c"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/include/wlan_api.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/hw_interface/hw_api.c"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/storerecall/dset.c"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/include/wmi_api.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/include/hif_internal.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/include/dset.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/include/dbglog_api.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/include/common_api.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/include/bmi.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/include/aggr_recv_api.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/include/a_drv.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/include/a_debug.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/hcd/hcd_api.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/driver/driver_txrx.c"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/driver/driver_netbuf.c"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/driver/driver_init.c"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/driver/driver_diag.c"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/bmi/bmi.c"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/api_interface/api_txrx.c"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/api_interface/api_init.c"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/include/spi_hcd_if.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/wmi/wmi_host.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/util/util.c"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/storerecall/storerecall.c"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/reorder/rcv_aggr.c"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/qapi/qcom_legacy.c"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/include/netbuf.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/include/ieee80211.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/common_src/include/htc_api.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/custom_src/stack_custom/cust_api_stack_offload.c"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/custom_src/qapi/custom_qcom_api.c"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/custom_src/include/cust_netbuf.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/custom_src/include/a_osapi.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/custom_src/include/a_config.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/custom_src/api_interface/cust_api_wmi_rx.c"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/custom_src/api_interface/cust_api_ioctl.c"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/custom_src/driver/cust_driver_netbuf.c"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/custom_src/include/wlan_config.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/custom_src/stack_custom/qca_structs.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/custom_src/stack_custom/custom_stack_offload.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/custom_src/stack_custom/cust_api_stack_txrx.c"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/custom_src/include/custom_wlan_api.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/custom_src/include/a_types.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/custom_src/hw_interface/cust_spi_hcd.c"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/custom_src/driver/cust_driver_main.c"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/custom_src/api_interface/cust_api_txrx.c"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/custom_src/api_interface/cust_api_init.c"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/include/wmi.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/include/dbglog.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/include/athdefs.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/include/dbglog_id.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/include/bmi_msg.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/include/AR6002/hw2.0/hw/hw20_gpio_reg.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/include/AR6002/hw2.0/hw/hw20_apb_map.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/include/AR6002/AR6K_version.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/include/AR6002/hw4.0/hw/hw40_rtc_wlan_reg.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/include/AR6002/hw4.0/hw/hw40_rtc_reg.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/include/wlan_defs.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/include/targaddrs.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/include/pmu.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/include/pkt_log.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/include/p2p.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/include/htc_services.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/include/htc.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/include/AR6002/hw2.0/hw/hw20_vmc_reg.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/include/AR6002/hw2.0/hw/hw20_uart_reg.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/include/AR6002/hw2.0/hw/hw20_si_reg.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/include/AR6002/hw2.0/hw/hw20_rtc_reg.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/include/AR6002/hw2.0/hw/hw20_mbox_reg.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/include/AR6002/hw2.0/hw/hw20_mbox_host_reg.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/port/wifi_common.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/qcom_api.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/atheros_stack_offload.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/atheros_wifi_internal.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/atheros_wifi_api.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/atheros_wifi.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/port/drivers/lpspi_edma_freertos/wifi_spi.h"
"${ProjDirPath}/../../../../../../middleware/wifi_qca/port/drivers/lpspi_edma_freertos/wifi_spi.c"
"${ProjDirPath}/../../../../../../devices/MIMXRT1052/drivers/fsl_lpspi.c"
"${ProjDirPath}/../../../../../../devices/MIMXRT1052/drivers/fsl_lpspi.h"
"${ProjDirPath}/../../../../../../devices/MIMXRT1052/drivers/fsl_common.h"
"${ProjDirPath}/../../../../../../devices/MIMXRT1052/drivers/fsl_common.c"
"${ProjDirPath}/../../../../../../devices/MIMXRT1052/drivers/fsl_lpspi_edma.h"
"${ProjDirPath}/../../../../../../devices/MIMXRT1052/drivers/fsl_lpspi_edma.c"
"${ProjDirPath}/../../../../../../devices/MIMXRT1052/drivers/fsl_edma.h"
"${ProjDirPath}/../../../../../../devices/MIMXRT1052/drivers/fsl_edma.c"
"${ProjDirPath}/../../../../../../devices/MIMXRT1052/drivers/fsl_dmamux.h"
"${ProjDirPath}/../../../../../../devices/MIMXRT1052/drivers/fsl_dmamux.c"
"${ProjDirPath}/../../../../../../devices/MIMXRT1052/drivers/fsl_gpio.h"
"${ProjDirPath}/../../../../../../devices/MIMXRT1052/drivers/fsl_gpio.c"
"${ProjDirPath}/../../../../../../devices/MIMXRT1052/drivers/fsl_clock.h"
"${ProjDirPath}/../../../../../../devices/MIMXRT1052/drivers/fsl_clock.c"
"${ProjDirPath}/../../../../../../devices/MIMXRT1052/system_MIMXRT1052.c"
"${ProjDirPath}/../../../../../../devices/MIMXRT1052/system_MIMXRT1052.h"
"${ProjDirPath}/../../../../../../devices/MIMXRT1052/gcc/startup_MIMXRT1052.S"
"${ProjDirPath}/../../../../../../devices/MIMXRT1052/drivers/fsl_lpuart.h"
"${ProjDirPath}/../../../../../../devices/MIMXRT1052/drivers/fsl_lpuart.c"
"${ProjDirPath}/../../../../../../devices/MIMXRT1052/utilities/io/fsl_io.c"
"${ProjDirPath}/../../../../../../devices/MIMXRT1052/utilities/io/fsl_io.h"
"${ProjDirPath}/../../../../../../devices/MIMXRT1052/utilities/log/fsl_log.c"
"${ProjDirPath}/../../../../../../devices/MIMXRT1052/utilities/log/fsl_log.h"
"${ProjDirPath}/../../../../../../devices/MIMXRT1052/utilities/str/fsl_str.c"
"${ProjDirPath}/../../../../../../devices/MIMXRT1052/utilities/str/fsl_str.h"
"${ProjDirPath}/../../../../../../devices/MIMXRT1052/utilities/fsl_debug_console.c"
"${ProjDirPath}/../../../../../../devices/MIMXRT1052/utilities/fsl_debug_console.h"
"${ProjDirPath}/../../../../../../devices/MIMXRT1052/utilities/fsl_debug_console_conf.h"
"${ProjDirPath}/../../../../../../devices/MIMXRT1052/drivers/fsl_iomuxc.h"
"${ProjDirPath}/../../../../../../devices/MIMXRT1052/utilities/fsl_assert.c"
"${ProjDirPath}/../../../../../../rtos/freertos/Source/portable/MemMang/heap_4.c"
)


set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -T${ProjDirPath}/MIMXRT1052xxxxx_ram.ld -static")

set(CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG "${CMAKE_EXE_LINKER_FLAGS_SDRAM_DEBUG} -T${ProjDirPath}/MIMXRT1052xxxxx_sdram.ld -static")

set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} -T${ProjDirPath}/MIMXRT1052xxxxx_ram.ld -static")

set(CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE "${CMAKE_EXE_LINKER_FLAGS_SDRAM_RELEASE} -T${ProjDirPath}/MIMXRT1052xxxxx_sdram.ld -static")

TARGET_LINK_LIBRARIES(qca_demo.elf -Wl,--start-group)
target_link_libraries(qca_demo.elf debug m)

target_link_libraries(qca_demo.elf debug c)

target_link_libraries(qca_demo.elf debug gcc)

target_link_libraries(qca_demo.elf debug nosys)

target_link_libraries(qca_demo.elf optimized m)

target_link_libraries(qca_demo.elf optimized c)

target_link_libraries(qca_demo.elf optimized gcc)

target_link_libraries(qca_demo.elf optimized nosys)

target_link_libraries(qca_demo.elf optimized m)

target_link_libraries(qca_demo.elf optimized c)

target_link_libraries(qca_demo.elf optimized gcc)

target_link_libraries(qca_demo.elf optimized nosys)

target_link_libraries(qca_demo.elf optimized m)

target_link_libraries(qca_demo.elf optimized c)

target_link_libraries(qca_demo.elf optimized gcc)

target_link_libraries(qca_demo.elf optimized nosys)

TARGET_LINK_LIBRARIES(qca_demo.elf -Wl,--end-group)

