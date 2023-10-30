add_executable(
    image_processor
    base_filter.cpp
    pipeline.cpp

    filter_blur.cpp
    filter_crop.cpp
    filter_edge.cpp
    filter_grayscale.cpp
    filter_negative.cpp
    filter_sharp.cpp
    filter_rainbow.cpp
    
    filter_setting.cpp
    filter_production.cpp
    image_processor.cpp
    image.cpp
    parser.cpp
    rgb.cpp
    rgbmatrix.cpp
    bmp_editor.cpp
)
