#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "../../clap.h"

#define CLAP_EXT_VST2_CONVERT "clap/draft/vst2-convert"

struct clap_plugin_vst2_convert {
   // Copies the name and VST2 plugin id that we can convert from.
   // Returns the lenght of the name.
   // [thread-safe]
   int32_t (*get_vst2_plugin_id)(struct clap_plugin *plugin,
                                 uint32_t *          vst2_plugin_id,
                                 char *              name,
                                 uint32_t            name_size);

   // Loads the plugin state from stream using the VST2 chunk.
   // [main-thread]
   bool (*restore_vst2_state)(struct clap_plugin * plugin,
                              struct clap_istream *stream);

   // converts the vst2 param id and normalized value to clap param id and
   // normalized value.
   // [thread-safe]
   bool (*convert_normalize_value)(
      struct clap_plugin *    plugin,
      uint32_t                vst2_param_id,
      double                  vst2_normalized_value,
      uint32_t *              clap_param_id,
      union clap_param_value *clap_normalized_value);

   // converts the vst2 param id and plain value to clap param id and
   // plain value.
   // [thread-safe]
   bool (*convert_plain_value)(struct clap_plugin *    plugin,
                               uint32_t                vst2_param_index,
                               double                  vst2_plain_value,
                               uint32_t *              clap_param_index,
                               union clap_param_value *clap_plain_value);
};

#ifdef __cplusplus
}
#endif