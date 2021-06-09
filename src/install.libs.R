

dest <- file.path(R_PACKAGE_DIR, paste0('libs', R_ARCH))
dir.create(dest, recursive = TRUE, showWarnings = FALSE)

files <- Sys.glob(paste0("*", SHLIB_EXT))
file.copy(files, dest, overwrite = TRUE)

if(file.exists("symbols.rds"))
    file.copy("symbols.rds", dest, overwrite = TRUE)

fs::dir_copy("tensorflow/bazel-bin/tensorflow/compiler/xla/r-client", dest)