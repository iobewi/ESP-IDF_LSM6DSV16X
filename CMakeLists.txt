idf_component_register( SRC_DIRS "src"
                        SRC_DIRS "src/config"
                        SRC_DIRS "src/ctrl"
                        SRC_DIRS "src/data"
                        SRC_DIRS "src/embedded"
                        SRC_DIRS "src/status"
                        INCLUDE_DIRS "include"
                        REQUIRES driver I2CDevices json
) 

# Inclure le fichier Kconfig
set(COMPONENT_KCONFIG Kconfig)