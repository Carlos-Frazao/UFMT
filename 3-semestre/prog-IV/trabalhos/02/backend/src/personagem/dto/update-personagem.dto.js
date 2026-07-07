"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.UpdatePersonagemDto = void 0;
const mapped_types_1 = require("@nestjs/mapped-types");
const create_personagem_dto_1 = require("./create-personagem.dto");
class UpdatePersonagemDto extends (0, mapped_types_1.PartialType)(create_personagem_dto_1.CreatePersonagemDto) {
}
exports.UpdatePersonagemDto = UpdatePersonagemDto;
//# sourceMappingURL=update-personagem.dto.js.map